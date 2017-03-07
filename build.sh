#!/bin/bash

MODULES_LOAD_DIR=/etc/modules-load.d/
MODULE_NAME=beagle_gpio

make install

echo ${MODULE_NAME} > ${MODULES_LOAD_DIR}/${MODULE_NAME}.conf
