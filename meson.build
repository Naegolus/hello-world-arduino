
project('arduino_bare', 'cpp', default_options : ['cpp_std=c++11'])

c_args = [
  '-DF_CPU=16000000UL',
  '-Os',
  '-Wall',
  '-ffunction-sections',
  '-fdata-sections',
  '-DCONFIG_PROC_NUM_MAX_CHILDREN_DEFAULT=5',
  '-DCONFIG_PROC_INFO_BUFFER_SIZE=512',
  '-DCONFIG_PROC_HAVE_LOG=1',
]

link_args = [
  '-Wl,--gc-sections',
]

srcs = [
  'SystemCore/Processing.cpp',
  'SystemCore/Log.cpp',
  'SystemCore/targets/stm32/SystemDebugging.cpp',
  'SystemCore/targets/stm32/SingleWireTransfering.cpp',
  'src/main.cpp',
  'src/AvrSupervising.cpp',
]

myApp = executable('firmware',
  srcs,
  cpp_args : c_args,
  link_args : link_args,
  install : false,
  include_directories : include_directories([
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

