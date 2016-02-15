# A ubuntu 14LTS based esp-open-sdk toolchain

**USB Serial port setup**

    # run this command to find vendor_id and product_id and modify Vagrantfile
    $> VBoxManage list usbhost

**Example**

The blinky.c is a modified version for [ESP Witty](https://gregwareblog.wordpress.com/2016/01/10/esp-witty/) dev board

which will blink following LEDs in turn:

GPIO 12: green

GPIO 13: blue

GPIO 15: red

**AT firmware download**

[AT firmware v 0.9.5](http://iot-playground.com/swdownload/ESPfirmware/v0.9.5.2%20AT%20Firmware.bin)


