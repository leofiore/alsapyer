# setup.py
#
# A ridicolously simple Python binding for libalsaplayer
#
# Author: Leonardo
#
#            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
#                    Version 2, December 2004
#
# Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
#
# Everyone is permitted to copy and distribute verbatim or modified
# copies of this license document, and changing it is allowed as long
# as the name is changed.
#
#            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
#   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
#
#  0. You just DO WHAT THE FUCK YOU WANT TO.
#
#
## {{{ http://code.activestate.com/recipes/502261/ (r1)
#!/usr/bin/env python
from distutils.core import setup
from distutils.extension import Extension
from subprocess import Popen, PIPE


def pkgconfig(*packages, **kw):
    flag_map = {'-I': 'include_dirs', '-L': 'library_dirs', '-l': 'libraries'}
    p = Popen(
        "pkg-config --libs --cflags".split() + list(packages),
        stdout=PIPE
    )
    for token in p.communicate()[0].decode().strip().split():
        kw.setdefault(flag_map.get(token[:2]), []).append(token[2:])
    return kw

setup(
    name="alsapyer",
    version="0.2",
    description="A ridicolously simple Python binding for libalsaplayer",
    author="Leonardo",
    author_email="leonardo@perpli.me",
    url="http://github.com/leofiore/alsapyer",
    license="WTFPL",
    ext_modules=[
        Extension("alsapyer", ["alsapyer/alsapyer.c"],
                  **pkgconfig('alsaplayer')),
    ],
    long_description="""
    This is a simple and lightweight python binding for libalsaplayer.

    alsapyer is written in C, and do not requires any third party library
    except libalsaplayer itself.

    It maps 1:1 all the alsaplayer exposed functions, so if you already
    used it you're ready for shine.
    """,
    classifiers=[
        "Programming Language :: Python :: 2",
        "Programming Language :: Python :: 2.7",
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: 3.4",
        "Programming Language :: C",
        "Development Status :: 4 - Beta",
        "Intended Audience :: Developers",
        "Topic :: Software Development :: Libraries :: Python Modules"
    ]

)
## end of http://code.activestate.com/recipes/502261/ }}}

