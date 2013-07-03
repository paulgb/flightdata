#!./python_i386

from os import chdir

print 'ok'
from ctypes import cdll

a = cdll.LoadLibrary('dbextract.exe.so')

chdir('../datasource/skyteam/app')

print a.init('serverdll.dll', 'foo')

