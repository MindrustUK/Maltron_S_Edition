// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "gpio.h"
#include "matrix.h"
#include "mcp23018.h"
#include "util.h"
#include "wait.h"
#include "debug.h"

// Pull ADDR (Pin 15) to ground for an easy 0x20
// See MCP23018 documentation for how to set alternate addresses
#define I2C_ADDR 0x20

// Set the error counter to 0
static uint8_t mcp23018_errors = 0;

static void led_output_pins_init(void) {
    // Blink all LEDs twice on boot.

    // Set output pins
    setPinOutput(B4);                       // initialize B4 for LED
    setPinOutput(B5);                       // initialize B5 for LED
    setPinOutput(B6);                       // initialize B6 for LED
    setPinOutput(B7);                       // initialize B7 for LED
    setPinOutput(B12);                      // initialize B12 for LED
    setPinOutput(B13);                      // initialize B13 for LED
    setPinOutput(B14);                      // initialize B14 for LED
    setPinOutput(B15);                      // initialize B15 for LED
    
    // Debug message
    uprintf("Blinking all leds\n");

    // Attempt to blink LEDs twice
    writePinLow(B4);
    writePinLow(B5);
    writePinLow(B6);
    writePinLow(B7);
    writePinLow(B12);
    writePinLow(B13);
    writePinLow(B14);
    writePinLow(B15);
    wait_ms(250);
    writePinHigh(B4);
    writePinHigh(B5);
    writePinHigh(B6);
    writePinHigh(B7);
    writePinHigh(B12);
    writePinHigh(B13);
    writePinHigh(B14);
    writePinHigh(B15);
    wait_ms(250);
    writePinLow(B4);
    writePinLow(B5);
    writePinLow(B6);
    writePinLow(B7);
    writePinLow(B12);
    writePinLow(B13);
    writePinLow(B14);
    writePinLow(B15);
    wait_ms(250);
    writePinHigh(B4);
    writePinHigh(B5);
    writePinHigh(B6);
    writePinHigh(B7);
    writePinHigh(B12);
    writePinHigh(B13);
    writePinHigh(B14);
    writePinHigh(B15);
    wait_ms(250);
}

static void expander_init(void) {
    mcp23018_init(I2C_ADDR);
}

static void expander_init_cols(void) {
    mcp23018_errors += !mcp23018_set_config(I2C_ADDR, mcp23018_PORTA, ALL_INPUT);
    mcp23018_errors += !mcp23018_set_config(I2C_ADDR, mcp23018_PORTB, ALL_INPUT);
}

static matrix_row_t expander_read_row(void) {
    if (mcp23018_errors) {
        return 0;
    }

    uint8_t ret_a = 0xFF;
    uint8_t ret_b = 0xFF;
    uint16_t ret = 0x00;
    mcp23018_errors += !mcp23018_readPins(I2C_ADDR, mcp23018_PORTA, &ret_a);
    mcp23018_errors += !mcp23018_readPins(I2C_ADDR, mcp23018_PORTB, &ret_b);

    ret_a = (~ret_a);
    ret_b = (~ret_b);
    ret = ret_a + (((uint16_t)ret_b) << 8);

    return (uint16_t)ret;
}

static void expander_scan(void) {
    if (!mcp23018_errors) {
        return;
    }

    static uint16_t mcp23018_reset_loop = 0;
    if (++mcp23018_reset_loop > 0x1FFF) {
        // tuned to about 5s given the current scan rate
        dprintf("trying to reset mcp23018\n");
        uprintf("trying to reset mcp23018\n");
        mcp23018_reset_loop = 0;
        mcp23018_errors     = 0;
        // expander_unselect_rows();
        expander_init_cols();
    }
}

static void init_cols(void) {
    // STM32 BlackPill - We don't want to read any colums using the onboard chip.
    // Expander
    expander_init_cols();
}

static matrix_row_t read_cols(void) {
    return expander_read_row();
}

static void unselect_rows(void) {
    // STM32 BlackPill
    setPinInput(A0);
    setPinInput(A1);
    setPinInput(A2);
    setPinInput(A3);
    setPinInput(A4);
    setPinInput(A5);
    setPinInput(A6);
    setPinInput(A7);
    writePinLow(A0);
    writePinLow(A1);
    writePinLow(A2);
    writePinLow(A3);
    writePinLow(A4);
    writePinLow(A5);
    writePinLow(A6);
    writePinLow(A7);
}

static void unselect_row(uint8_t row) {
    // STM32 Black Pill
    switch (row) {
        case 0:
            setPinInput(A0);
            writePinLow(A0);
            break;
        case 1:
            setPinInput(A1);
            writePinLow(A1);
            break;
        case 2:
            setPinInput(A2);
            writePinLow(A2);
            break;
        case 3:
            setPinInput(A3);
            writePinLow(A3);
            break;
        case 4:
            setPinInput(A4);
            writePinLow(A4);
            break;
        case 5:
            setPinInput(A5);
            writePinLow(A5);
            break;
        case 6:
            setPinInput(A6);
            writePinLow(A6);
            break;
        case 7:
            setPinInput(A7);
            writePinLow(A7);
            break;
    }
}

static void select_row(uint8_t row) {
    // STM32 Black Pill
    switch (row) {
        case 0:
            setPinOutput(A0);
            writePinLow(A0);
            break;
        case 1:
            setPinOutput(A1);
            writePinLow(A1);
            break;
        case 2:
            setPinOutput(A2);
            writePinLow(A2);
            break;
        case 3:
            setPinOutput(A3);
            writePinLow(A3);
            break;
        case 4:
            setPinOutput(A4);
            writePinLow(A4);
            break;
        case 5:
            setPinOutput(A5);
            writePinLow(A5);
            break;
        case 6:
            setPinOutput(A6);
            writePinLow(A6);
            break;
        case 7:
            setPinOutput(A7);
            writePinLow(A7);
            break;
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Store last value of row prior to reading
    matrix_row_t last_row_value = current_matrix[current_row];

    // Clear data in matrix row
    current_matrix[current_row] = 0;

    // Select row and wait for row selection to stabilize
    select_row(current_row);
    // Skip the wait_us(30); as i2c is slow enough to debounce the io changes

    current_matrix[current_row] = read_cols();

    unselect_row(current_row);

    return (last_row_value != current_matrix[current_row]);
}

void matrix_init_custom(void) {
    led_output_pins_init();

    expander_init();

    unselect_rows();
    init_cols();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    expander_scan();

    bool changed = false;
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        changed |= read_cols_on_row(current_matrix, current_row);
    }
    return changed;
}
