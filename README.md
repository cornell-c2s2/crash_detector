### Platformio Setup

### Setup the Venv

```
python3 -m venv venv
pip install -r requirements.txt
```

### Everytime Setup

Before you start development with `platformio` always start by setting up your virtual environment:
```. venv/bin/activate```

You'll know the virtual environment is active when your shell always starts with `(venv)`.
### Compiling Native

```pio run -e native```

### Running native

```.pio/build/native/program```

### Installing JLink on Ubuntu

JLink is required in order to upload from ubuntu using `platformio`.

Download the JLink_Linux_V644b_x86_64.deb file from https://www.segger.com/downloads/ jlink/JLink_Linux_x86_64.deb After downloading the file, run the command below to install the software: > sudo dpkg -i ~/Downloads/JLink_Linux_V644b_x86_64.deb Symbolic links to executables are installed in /usr/bin directory.

### Build and Upload to hi5

This example command builds and runs the hi5 hello world program.

```pio run -e hi5-hello -t upload```

Any `pio run` invocation post-fixed with `-t upload` means to upload to the hi5 board if it is connected.

### Build and run native tests

```pio test -e native_test```


### Compiling Arduino

```
pio run -e arduino
```