build_args = [
	'-Wall', '-Wextra', '-Wdouble-promotion', '-Wformat-security', '-Wformat-type-confusion',  
	'-Winit-self', '-Wswitch-default', '-Wstrict-overflow=4', '-Walloca', '-Wshadow', '-pedantic',
	'-Wcast-qual', '-Wconversion', '-Wdate-time', '-Wstrict-prototypes', '-Wmissing-prototypes',
	'-Winvalid-pch', '-Wmissing-variable-declarations', '-Wunreachable-code-aggressive',
	'-Wextra-semi-stmt', '-Wused-but-marked-unused', '-Wcast-align', '-Wdocumentation'
]

project_source_files = [
	'main.c',
  'parse_input.c',
  'parse_wrapper.c',
]

executable(
	'passcliman', 
	project_source_files,
	install : true,
  dependencies : passwordlib_dep,  
	c_args : build_args
)
