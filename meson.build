
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
  'src/main.cpp',
  'SystemCore/Processing.cpp',
  'SystemCore/targets/stm32/SystemDebugging.cpp',
  'SystemCore/targets/stm32/SingleWireTransfering.cpp',
  'SystemCore/Log.cpp',
]

executable('firmware',
  srcs,
  cpp_args : c_args,
  link_args : link_args,
  install : false,
  include_directories : include_directories([
    './SystemCore',
    './src',
  ]),
)

# optional
#custom_target('hex',
#  input : 'firmware',
#  output : 'firmware.hex',
#  command : ['avr-objcopy', '-O', 'ihex', '@INPUT@', '@OUTPUT@'],
#  depend_files : 'firmware'
#)

