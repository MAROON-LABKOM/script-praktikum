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

#define SECOND 5000000    // micros

// A NMEA 0183 sentence can have a maximum of 80 characters plus a
// carriage return and a line feed

const char gps_tx_data[][80] = {
"$GPGGA,123131.906,0635.967,S,10648.701,E,1,12,1.0,0.0,M,0.0,M,,*7A\r\n",
"$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30\r\n",
"$GPRMC,123131.906,A,0635.967,S,10648.701,E,161.3,043.3,061224,000.0,W*6C\r\n",
"$GPGGA,123132.906,0635.935,S,10648.732,E,1,12,1.0,0.0,M,0.0,M,,*7E\r\n",
"$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30\r\n",
"$GPRMC,123132.906,A,0635.935,S,10648.732,E,205.3,136.8,061224,000.0,W*61\r\n",
"$GPGGA,123133.906,0635.976,S,10648.771,E,1,12,1.0,0.0,M,0.0,M,,*7F\r\n",
"$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30\r\n",
"$GPRMC,123133.906,A,0635.976,S,10648.771,E,222.3,220.4,061224,000.0,W*6D\r\n",
"$GPGGA,123134.906,0636.023,S,10648.731,E,1,12,1.0,0.0,M,0.0,M,,*76\r\n",
"$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30\r\n",
"$GPRMC,123134.906,A,0636.023,S,10648.731,E,156.4,247.0,061224,000.0,W*66\r\n",
"$GPGGA,123135.906,0636.040,S,10648.690,E,1,12,1.0,0.0,M,0.0,M,,*78\r\n",
"$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30\r\n",
"$GPRMC,123135.906,A,0636.040,S,10648.690,E,193.0,293.2,061224,000.0,W*6E\r\n",
"$GPGGA,123136.906,0636.019,S,10648.641,E,1,12,1.0,0.0,M,0.0,M,,*7B\r\n",
"$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30\r\n",
"$GPRMC,123136.906,A,0636.019,S,10648.641,E,261.8,008.1,061224,000.0,W*68\r\n",
"$GPGGA,123137.906,0635.947,S,10648.651,E,1,12,1.0,0.0,M,0.0,M,,*7A\r\n",
"$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30\r\n",
"$GPRMC,123137.906,A,0635.947,S,10648.651,E,152.1,091.7,061224,000.0,W*65\r\n",
"$GPGGA,123138.906,0635.948,S,10648.694,E,1,12,1.0,0.0,M,0.0,M,,*73\r\n",
"$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30\r\n",
"$GPRMC,123138.906,A,0635.948,S,10648.694,E,070.8,158.0,061224,000.0,W*67\r\n",
"$GPGGA,123139.906,0635.967,S,10648.701,E,1,12,1.0,0.0,M,0.0,M,,*72\r\n",
"$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30\r\n",
"$GPRMC,123139.906,A,0635.967,S,10648.701,E,070.8,158.0,061224,000.0,W*66\r\n",
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

