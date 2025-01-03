project('nanoid', 'c', version: '2.0.0')

install_headers('nanoid.h')

if host_machine.system() in ['openbsd', 'darwin'] or \
   (host_machine.system() == 'sunos' and host_machine.kernel() == 'solaris')
  install_man('openbsd/nanoid.3')
else
  install_man('nanoid.3')
endif

executable('nanoidgen', 'nanoidgen.c', install: true)

install_man('nanoidgen.1')
