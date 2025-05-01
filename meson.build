
# meson setup --cross-file tools-dev/cross/meson-cross-avr.txt build-avr

project('arduino_bare', 'cpp', default_options : ['cpp_std=c++11'])

home_dir = run_command('sh', '-c', 'echo $HOME', check: true).stdout().strip()
message('Home directory: ' + home_dir)

arduino_core = home_dir + '/.arduino15/packages/arduino/hardware/avr/1.8.6/cores/arduino'
arduino_variant = home_dir + '/.arduino15/packages/arduino/hardware/avr/1.8.6/variants/micro'

c_args = [
  '-mmcu=atmega32u4',
  '-DF_CPU=16000000UL',
  '-Os',
  '-Wall',
  '-ffunction-sections',
  '-fdata-sections',
  '-nostdlib',
  '-DCONFIG_PROC_NUM_MAX_CHILDREN_DEFAULT=5',
  '-DCONFIG_PROC_INFO_BUFFER_SIZE=512',
  '-DCONFIG_PROC_HAVE_LOG=1',
]

link_args = [
  '-mmcu=atmega32u4',
  '-Wl,--gc-sections',
  '-Wl,-T../atmega32u4.ld',
]

srcs = [
  'SystemCore/Processing.cpp',
  'SystemCore/Log.cpp',
  'SystemCore/targets/stm32/SystemDebugging.cpp',
  'SystemCore/targets/stm32/SingleWireTransfering.cpp',
  'src/LibcCustom.cpp',
  'src/main.cpp',
  'src/AvrSupervising.cpp',
]

arduino_srcs = files(
  arduino_core + '/wiring.c',
  arduino_core + '/wiring_analog.c',
  arduino_core + '/wiring_digital.c',
  arduino_core + '/wiring_pulse.c',
  arduino_core + '/wiring_shift.c',
  arduino_core + '/HardwareSerial.cpp',
  arduino_core + '/Print.cpp',
  arduino_core + '/Stream.cpp',
  arduino_core + '/Tone.cpp',
  arduino_core + '/WMath.cpp',
  arduino_core + '/WString.cpp',
)

all_srcs = srcs + arduino_srcs

myApp = executable('firmware',
  srcs,
  cpp_args : c_args,
  link_args : link_args,
  install : false,
  include_directories : include_directories([
    arduino_core,
    arduino_variant,
    './SystemCore/targets/stm32',
    './SystemCore',
    './src',
  ]),
)

custom_target(
  'app-hex',
  input : myApp,
  output : 'firmware.hex',
  command : ['avr-objcopy', '-O', 'ihex', '@INPUT@', '@OUTPUT@'],
  build_by_default : true,
)

