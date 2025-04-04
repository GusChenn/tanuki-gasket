# How to generate firmware

Just copy the 'tanuki_gasket' folder to you qmk keyboards folder. On MacOS it is located on '~/qmk_firmware/keyboards'. Then run the following command to generate the firmware:

```bash
qmk compile -kb tanuki_gasket -km default
```
