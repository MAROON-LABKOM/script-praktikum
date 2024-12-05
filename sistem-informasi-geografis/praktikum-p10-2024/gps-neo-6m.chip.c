// For information and examples see:
// https://link.wokwi.com/custom-chips-alpha
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2022 Uri Shaked / wokwi.com

// https://wokwi.com/makers/urish

// original project https://wokwi.com/projects/333785509332517459

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>    // contains strlen() function

#define LEN(arr) ((int)(sizeof(arr) / sizeof(arr)[0]))    // macro

#define SECOND 1000000    // micros

// A NMEA 0183 sentence can have a maximum of 80 characters plus a
// carriage return and a line feed

const char gps_tx_data[][80] = { // Hypothetical Data
  "$GPGGA,172914.049,0635.953033,S,10648.742651,W,1,12,1.0,0.0,M,0.0,M,,*60\r\n",
  "$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30\r\n",
  "$GPRMC,172914.049,A,0635.953033,S,10648.742651,W,009.7,025.9,060622,000.0,W*74\r\n",
};


typedef struct {
  uart_dev_t uart0;
  uint32_t   gps_tx_index;
} chip_state_t;


static void chip_timer_event  (void *user_data);


void chip_init(void) {

  setvbuf(stdout, NULL, _IOLBF, 1024);                // ???     // Disable buffering for debug logs

  chip_state_t *chip = malloc(sizeof(chip_state_t));

  const uart_config_t uart_config = {
    .tx         = pin_init("TX", INPUT_PULLUP),
    .rx         = pin_init("RX", INPUT),
    .baud_rate  = 9600,
    .user_data  = chip,
  };

  chip->uart0        = uart_init(&uart_config);

  chip->gps_tx_index = 0;

  const timer_config_t timer_config = {
    .callback  = chip_timer_event,
    .user_data = chip,
  };

  timer_t timer = timer_init(&timer_config);

  timer_start(timer, SECOND, true);

  printf("GPS Chip initialized!\n");         // prints to web browser console (developer tools)

}

void chip_timer_event(void *user_data) {

  chip_state_t *chip = (chip_state_t*) user_data;

  printf("chip_timer_event\n");
  //  printf ("LEN(gps_tx_data):  %d\n", LEN(gps_tx_data)   );    // number of messages
  //  printf ("message length  :  %d\n", strlen(message)    );    // actual message length
  //  printf ("gps_tx_index    :  %u\n", chip->gps_tx_index );    // message index

  const char * message = gps_tx_data[chip->gps_tx_index++];

  uart_write(chip->uart0, (uint8_t *) message, strlen(message));

  if (chip->gps_tx_index >= LEN(gps_tx_data)) {
    chip->gps_tx_index = 0;
  }
}

