// Copyright 2022 Mehmet Can (@MindrustUK)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// Define Matrix Size
#define MATRIX_ROWS 8
#define MATRIX_COLS 16

// Setup Pins for I2C, Needed for MCP23018 IO expander
#define I2C1_SCL_PIN        B9
#define I2C1_SDA_PIN        B8

// Hold ESC on start up to boot into bootloader mode
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 14