# setup for Vbuddy interface

# uses usbipd to search for the USB port that Vbuddy is connected to and share it with WSL
~/Documents/iac/lab0-devtools/tools/attach_usb.sh

# next enter the following command to find the name of your device:
ls /dev/ttyU*

#You should see a device name similar to this:
#/dev/ttyUSB0