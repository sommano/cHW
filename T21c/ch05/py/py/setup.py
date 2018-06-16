py_modules= ['pvnrt']

Emodule = Extension('pvnrt',
       libraries=['pvnrt'],
       library_dirs=['..'],
       sources = ['ideal.py.c'])

setup (name = 'pvnrt',
       version = '1.0',
version = '1.0',
       description = 'pressure * volume = n * R * Temperature',
       text_modules = [Emodule])
