/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:4;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=4 sts=4 sw=4 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Python 3                                                                     │
│ https://docs.python.org/3/license.html                                       │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/bits/bits.h"
#include "libc/calls/calls.h"
#include "libc/dce.h"
#include "libc/errno.h"
#include "libc/log/check.h"
#include "libc/log/log.h"
#include "libc/mem/mem.h"
#include "libc/runtime/gc.internal.h"
#include "libc/runtime/runtime.h"
#include "libc/runtime/symbols.internal.h"
#include "libc/stdio/stdio.h"
#include "libc/str/str.h"
#include "libc/sysv/consts/fileno.h"
#include "libc/sysv/consts/sig.h"
#include "libc/unicode/locale.h"
#include "libc/x/x.h"
#include "third_party/linenoise/linenoise.h"
#include "third_party/python/Include/abstract.h"
#include "third_party/python/Include/ceval.h"
#include "third_party/python/Include/dictobject.h"
#include "third_party/python/Include/fileutils.h"
#include "third_party/python/Include/funcobject.h"
#include "third_party/python/Include/import.h"
#include "third_party/python/Include/listobject.h"
#include "third_party/python/Include/moduleobject.h"
#include "third_party/python/Include/object.h"
#include "third_party/python/Include/pydebug.h"
#include "third_party/python/Include/pyerrors.h"
#include "third_party/python/Include/pylifecycle.h"
#include "third_party/python/Include/pymem.h"
#include "third_party/python/Include/pyport.h"
#include "third_party/python/Include/pythonrun.h"
#include "third_party/python/Include/unicodeobject.h"
#include "third_party/python/Include/yoink.h"
/* clang-format off */

STATIC_YOINK(".python/");
PYTHON_YOINK("__future__");
PYTHON_YOINK("_bootlocale");
PYTHON_YOINK("_collections_abc");
PYTHON_YOINK("_compat_pickle");
PYTHON_YOINK("_compression");
PYTHON_YOINK("_dummy_thread");
PYTHON_YOINK("_markupbase");
PYTHON_YOINK("_osx_support");
PYTHON_YOINK("_pyio");
PYTHON_YOINK("_sitebuiltins");
PYTHON_YOINK("_strptime");
PYTHON_YOINK("_sysconfigdata_m_cosmo_x86_64-cosmo");
PYTHON_YOINK("_threading_local");
PYTHON_YOINK("_weakrefset");
PYTHON_YOINK("abc");
PYTHON_YOINK("argparse");
PYTHON_YOINK("ast");
PYTHON_YOINK("base64");
PYTHON_YOINK("bdb");
PYTHON_YOINK("binhex");
PYTHON_YOINK("bisect");
PYTHON_YOINK("calendar");
PYTHON_YOINK("chunk");
PYTHON_YOINK("cmd");
PYTHON_YOINK("code");
PYTHON_YOINK("codecs");
PYTHON_YOINK("colorsys");
PYTHON_YOINK("configparser");
PYTHON_YOINK("contextlib");
PYTHON_YOINK("copy");
PYTHON_YOINK("copyreg");
PYTHON_YOINK("csv");
PYTHON_YOINK("datetime");
PYTHON_YOINK("decimal");
PYTHON_YOINK("difflib");
PYTHON_YOINK("doctest");
PYTHON_YOINK("dummy_threading");
PYTHON_YOINK("threading");
PYTHON_YOINK("enum");
PYTHON_YOINK("filecmp");
PYTHON_YOINK("fileinput");
PYTHON_YOINK("fnmatch");
PYTHON_YOINK("formatter");
PYTHON_YOINK("fractions");
PYTHON_YOINK("functools");
PYTHON_YOINK("genericpath");
PYTHON_YOINK("getopt");
PYTHON_YOINK("getpass");
PYTHON_YOINK("gettext");
PYTHON_YOINK("glob");
PYTHON_YOINK("hashlib");
PYTHON_YOINK("heapq");
PYTHON_YOINK("hmac");
PYTHON_YOINK("imghdr");
PYTHON_YOINK("imp");
PYTHON_YOINK("io");
PYTHON_YOINK("ipaddress");
PYTHON_YOINK("keyword");
PYTHON_YOINK("linecache");
PYTHON_YOINK("locale");
PYTHON_YOINK("macpath");
PYTHON_YOINK("macurl2path");
PYTHON_YOINK("mimetypes");
PYTHON_YOINK("modulefinder");
PYTHON_YOINK("netrc");
PYTHON_YOINK("ntpath");
PYTHON_YOINK("nturl2path");
PYTHON_YOINK("numbers");
PYTHON_YOINK("opcode");
PYTHON_YOINK("operator");
PYTHON_YOINK("optparse");
PYTHON_YOINK("os");
PYTHON_YOINK("pathlib");
PYTHON_YOINK("pickle");
PYTHON_YOINK("pickletools");
PYTHON_YOINK("pipes");
PYTHON_YOINK("pkgutil");
PYTHON_YOINK("platform");
PYTHON_YOINK("plistlib");
PYTHON_YOINK("posixpath");
PYTHON_YOINK("pprint");
PYTHON_YOINK("pstats");
PYTHON_YOINK("pty");
PYTHON_YOINK("pyclbr");
PYTHON_YOINK("queue");
PYTHON_YOINK("quopri");
PYTHON_YOINK("random");
PYTHON_YOINK("re");
PYTHON_YOINK("reprlib");
PYTHON_YOINK("runpy");
PYTHON_YOINK("sched");
PYTHON_YOINK("secrets");
PYTHON_YOINK("selectors");
PYTHON_YOINK("shelve");
PYTHON_YOINK("shlex");
PYTHON_YOINK("shutil");
PYTHON_YOINK("signal");
PYTHON_YOINK("site");
PYTHON_YOINK("sndhdr");
PYTHON_YOINK("socket");
PYTHON_YOINK("socketserver");
PYTHON_YOINK("sre_compile");
PYTHON_YOINK("sre_constants");
PYTHON_YOINK("sre_parse");
PYTHON_YOINK("stat");
PYTHON_YOINK("statistics");
PYTHON_YOINK("string");
PYTHON_YOINK("stringprep");
PYTHON_YOINK("struct");
PYTHON_YOINK("subprocess");
PYTHON_YOINK("symbol");
PYTHON_YOINK("symtable");
PYTHON_YOINK("sysconfig");
PYTHON_YOINK("tabnanny");
PYTHON_YOINK("tempfile");
PYTHON_YOINK("textwrap");
PYTHON_YOINK("this");
PYTHON_YOINK("token");
PYTHON_YOINK("tokenize");
PYTHON_YOINK("trace");
PYTHON_YOINK("traceback");
PYTHON_YOINK("tty");
PYTHON_YOINK("types");
PYTHON_YOINK("typing");
PYTHON_YOINK("uu");
PYTHON_YOINK("uuid");
PYTHON_YOINK("warnings");
PYTHON_YOINK("weakref");
PYTHON_YOINK("webbrowser");
PYTHON_YOINK("xdrlib");

#if !IsTiny()
PYTHON_YOINK("aifc");
PYTHON_YOINK("wave");
PYTHON_YOINK("sunau");
#endif

#if !IsTiny()
PYTHON_YOINK("dis");
PYTHON_YOINK("codeop");
PYTHON_YOINK("compileall");
PYTHON_YOINK("py_compile");
#endif

#if !IsTiny()
PYTHON_YOINK("cgi");
PYTHON_YOINK("pdb");
PYTHON_YOINK("cgitb");
PYTHON_YOINK("pydoc");
PYTHON_YOINK("timeit");
PYTHON_YOINK("profile");
PYTHON_YOINK("inspect");
PYTHON_YOINK("cProfile");
PYTHON_YOINK("tracemalloc");
#endif

#if !IsTiny()
PYTHON_YOINK("bz2");
PYTHON_YOINK("ssl");
PYTHON_YOINK("gzip");
PYTHON_YOINK("lzma");
PYTHON_YOINK("crypt");
PYTHON_YOINK("zipapp");
PYTHON_YOINK("ftplib");
PYTHON_YOINK("tarfile");
PYTHON_YOINK("zipfile");
PYTHON_YOINK("telnetlib");
PYTHON_YOINK("antigravity");
PYTHON_YOINK("rlcompleter");
#endif

PYTHON_YOINK("collections");
PYTHON_YOINK("collections.abc");

PYTHON_YOINK("json");
PYTHON_YOINK("json.decoder");
PYTHON_YOINK("json.encoder");
PYTHON_YOINK("json.scanner");
PYTHON_YOINK("json.tool");

PYTHON_YOINK("html");
PYTHON_YOINK("html.entities");
PYTHON_YOINK("html.parser");

PYTHON_YOINK("http");
PYTHON_YOINK("http.client");
PYTHON_YOINK("http.cookiejar");
PYTHON_YOINK("http.cookies");
PYTHON_YOINK("http.server");

PYTHON_YOINK("email");
PYTHON_YOINK("email._encoded_words");
PYTHON_YOINK("email._header_value_parser");
PYTHON_YOINK("email._parseaddr");
PYTHON_YOINK("email._policybase");
PYTHON_YOINK("email.base64mime");
PYTHON_YOINK("email.charset");
PYTHON_YOINK("email.contentmanager");
PYTHON_YOINK("email.encoders");
PYTHON_YOINK("email.errors");
PYTHON_YOINK("email.feedparser");
PYTHON_YOINK("email.generator");
PYTHON_YOINK("email.header");
PYTHON_YOINK("email.headerregistry");
PYTHON_YOINK("email.iterators");
PYTHON_YOINK("email.message");
PYTHON_YOINK("email.mime");
PYTHON_YOINK("email.mime.application");
PYTHON_YOINK("email.mime.audio");
PYTHON_YOINK("email.mime.base");
PYTHON_YOINK("email.mime.image");
PYTHON_YOINK("email.mime.message");
PYTHON_YOINK("email.mime.multipart");
PYTHON_YOINK("email.mime.nonmultipart");
PYTHON_YOINK("email.mime.text");
PYTHON_YOINK("email.parser");
PYTHON_YOINK("email.policy");
PYTHON_YOINK("email.quoprimime");
PYTHON_YOINK("email.utils");
STATIC_YOINK(".python/email/architecture.rst");

PYTHON_YOINK("importlib");
PYTHON_YOINK("importlib._bootstrap");
PYTHON_YOINK("importlib._bootstrap_external");
PYTHON_YOINK("importlib.abc");
PYTHON_YOINK("importlib.machinery");
PYTHON_YOINK("importlib.util");

PYTHON_YOINK("logging");
PYTHON_YOINK("logging.config");
PYTHON_YOINK("logging.handlers");

PYTHON_YOINK("urllib");
PYTHON_YOINK("urllib.error");
PYTHON_YOINK("urllib.parse");
PYTHON_YOINK("urllib.request");
PYTHON_YOINK("urllib.response");
PYTHON_YOINK("urllib.robotparser");

PYTHON_YOINK("wsgiref");
PYTHON_YOINK("wsgiref.handlers");
PYTHON_YOINK("wsgiref.headers");
PYTHON_YOINK("wsgiref.simple_server");
PYTHON_YOINK("wsgiref.util");
PYTHON_YOINK("wsgiref.validate");

#if !IsTiny()
PYTHON_YOINK("sqlite3");
PYTHON_YOINK("sqlite3.dbapi2");
PYTHON_YOINK("sqlite3.dump");
#endif

#if !IsTiny()
PYTHON_YOINK("dbm");
PYTHON_YOINK("dbm.dumb");
PYTHON_YOINK("dbm.gnu");
PYTHON_YOINK("dbm.ndbm");
#endif

#if !IsTiny()
PYTHON_YOINK("xml");
PYTHON_YOINK("xml.dom.NodeFilter");
PYTHON_YOINK("xml.dom");
PYTHON_YOINK("xml.dom.domreg");
PYTHON_YOINK("xml.dom.expatbuilder");
PYTHON_YOINK("xml.dom.minicompat");
PYTHON_YOINK("xml.dom.minidom");
PYTHON_YOINK("xml.dom.pulldom");
PYTHON_YOINK("xml.dom.xmlbuilder");
PYTHON_YOINK("xml.etree.ElementInclude");
PYTHON_YOINK("xml.etree.ElementPath");
PYTHON_YOINK("xml.etree.ElementTree");
PYTHON_YOINK("xml.etree");
PYTHON_YOINK("xml.etree.cElementTree");
PYTHON_YOINK("xml.parsers");
PYTHON_YOINK("xml.parsers.expat");
PYTHON_YOINK("xml.sax");
PYTHON_YOINK("xml.sax._exceptions");
PYTHON_YOINK("xml.sax.expatreader");
PYTHON_YOINK("xml.sax.handler");
PYTHON_YOINK("xml.sax.saxutils");
PYTHON_YOINK("xml.sax.xmlreader");
PYTHON_YOINK("xmlrpc");
PYTHON_YOINK("xmlrpc.client");
PYTHON_YOINK("xmlrpc.server");
#endif

#if !IsTiny()
PYTHON_YOINK("multiprocessing");
PYTHON_YOINK("multiprocessing.connection");
PYTHON_YOINK("multiprocessing.context");
PYTHON_YOINK("multiprocessing.dummy");
PYTHON_YOINK("multiprocessing.dummy.connection");
PYTHON_YOINK("multiprocessing.forkserver");
PYTHON_YOINK("multiprocessing.heap");
PYTHON_YOINK("multiprocessing.managers");
PYTHON_YOINK("multiprocessing.pool");
PYTHON_YOINK("multiprocessing.popen_fork");
PYTHON_YOINK("multiprocessing.popen_forkserver");
PYTHON_YOINK("multiprocessing.popen_spawn_posix");
PYTHON_YOINK("multiprocessing.popen_spawn_win32");
PYTHON_YOINK("multiprocessing.process");
PYTHON_YOINK("multiprocessing.queues");
PYTHON_YOINK("multiprocessing.reduction");
PYTHON_YOINK("multiprocessing.resource_sharer");
PYTHON_YOINK("multiprocessing.semaphore_tracker");
PYTHON_YOINK("multiprocessing.sharedctypes");
PYTHON_YOINK("multiprocessing.spawn");
PYTHON_YOINK("multiprocessing.synchronize");
PYTHON_YOINK("multiprocessing.util");
#endif

#if !IsTiny()
PYTHON_YOINK("unittest");
PYTHON_YOINK("unittest.__main__");
PYTHON_YOINK("unittest.case");
PYTHON_YOINK("unittest.loader");
PYTHON_YOINK("unittest.main");
PYTHON_YOINK("unittest.mock");
PYTHON_YOINK("unittest.result");
PYTHON_YOINK("unittest.runner");
PYTHON_YOINK("unittest.signals");
PYTHON_YOINK("unittest.suite");
PYTHON_YOINK("unittest.util");
#endif

#if !IsTiny()
PYTHON_YOINK("venv");
PYTHON_YOINK("venv.__main__");
STATIC_YOINK(".python/venv/scripts/common/activate");
STATIC_YOINK(".python/venv/scripts/nt/Activate.ps1");
STATIC_YOINK(".python/venv/scripts/nt/activate.bat");
STATIC_YOINK(".python/venv/scripts/nt/deactivate.bat");
STATIC_YOINK(".python/venv/scripts/posix/activate.csh");
STATIC_YOINK(".python/venv/scripts/posix/activate.fish");
PYTHON_YOINK("ensurepip");
PYTHON_YOINK("ensurepip.__main__");
PYTHON_YOINK("ensurepip._uninstall");
STATIC_YOINK("ensurepip/_bundled/pip-18.1-py2-none-any.whl");
STATIC_YOINK("ensurepip/_bundled/setuptools-40.6.2-py2-none-any.whl");
PYTHON_YOINK("distutils");
PYTHON_YOINK("distutils._msvccompiler");
PYTHON_YOINK("distutils.archive_util");
PYTHON_YOINK("distutils.bcppcompiler");
PYTHON_YOINK("distutils.ccompiler");
PYTHON_YOINK("distutils.cmd");
PYTHON_YOINK("distutils.command");
PYTHON_YOINK("distutils.command.bdist");
PYTHON_YOINK("distutils.command.bdist_dumb");
PYTHON_YOINK("distutils.command.bdist_msi");
PYTHON_YOINK("distutils.command.bdist_rpm");
PYTHON_YOINK("distutils.command.bdist_wininst");
PYTHON_YOINK("distutils.command.build");
PYTHON_YOINK("distutils.command.build_clib");
PYTHON_YOINK("distutils.command.build_ext");
PYTHON_YOINK("distutils.command.build_py");
PYTHON_YOINK("distutils.command.build_scripts");
PYTHON_YOINK("distutils.command.check");
PYTHON_YOINK("distutils.command.clean");
PYTHON_YOINK("distutils.command.config");
PYTHON_YOINK("distutils.command.install");
PYTHON_YOINK("distutils.command.install_data");
PYTHON_YOINK("distutils.command.install_egg_info");
PYTHON_YOINK("distutils.command.install_headers");
PYTHON_YOINK("distutils.command.install_lib");
PYTHON_YOINK("distutils.command.install_scripts");
PYTHON_YOINK("distutils.command.register");
PYTHON_YOINK("distutils.command.sdist");
PYTHON_YOINK("distutils.command.upload");
PYTHON_YOINK("distutils.config");
PYTHON_YOINK("distutils.core");
PYTHON_YOINK("distutils.cygwinccompiler");
PYTHON_YOINK("distutils.debug");
PYTHON_YOINK("distutils.dep_util");
PYTHON_YOINK("distutils.dir_util");
PYTHON_YOINK("distutils.dist");
PYTHON_YOINK("distutils.errors");
PYTHON_YOINK("distutils.extension");
PYTHON_YOINK("distutils.fancy_getopt");
PYTHON_YOINK("distutils.file_util");
PYTHON_YOINK("distutils.filelist");
PYTHON_YOINK("distutils.log");
PYTHON_YOINK("distutils.msvc9compiler");
PYTHON_YOINK("distutils.msvccompiler");
PYTHON_YOINK("distutils.spawn");
PYTHON_YOINK("distutils.sysconfig");
PYTHON_YOINK("distutils.tests");
PYTHON_YOINK("distutils.tests.support");
PYTHON_YOINK("distutils.tests.test_archive_util");
PYTHON_YOINK("distutils.tests.test_bdist");
PYTHON_YOINK("distutils.tests.test_bdist_dumb");
PYTHON_YOINK("distutils.tests.test_bdist_msi");
PYTHON_YOINK("distutils.tests.test_bdist_rpm");
PYTHON_YOINK("distutils.tests.test_bdist_wininst");
PYTHON_YOINK("distutils.tests.test_build");
PYTHON_YOINK("distutils.tests.test_build_clib");
PYTHON_YOINK("distutils.tests.test_build_ext");
PYTHON_YOINK("distutils.tests.test_build_py");
PYTHON_YOINK("distutils.tests.test_build_scripts");
PYTHON_YOINK("distutils.tests.test_check");
PYTHON_YOINK("distutils.tests.test_clean");
PYTHON_YOINK("distutils.tests.test_cmd");
PYTHON_YOINK("distutils.tests.test_config");
PYTHON_YOINK("distutils.tests.test_config_cmd");
PYTHON_YOINK("distutils.tests.test_core");
PYTHON_YOINK("distutils.tests.test_cygwinccompiler");
PYTHON_YOINK("distutils.tests.test_dep_util");
PYTHON_YOINK("distutils.tests.test_dir_util");
PYTHON_YOINK("distutils.tests.test_dist");
PYTHON_YOINK("distutils.tests.test_extension");
PYTHON_YOINK("distutils.tests.test_file_util");
PYTHON_YOINK("distutils.tests.test_filelist");
PYTHON_YOINK("distutils.tests.test_install");
PYTHON_YOINK("distutils.tests.test_install_data");
PYTHON_YOINK("distutils.tests.test_install_headers");
PYTHON_YOINK("distutils.tests.test_install_lib");
PYTHON_YOINK("distutils.tests.test_install_scripts");
PYTHON_YOINK("distutils.tests.test_log");
PYTHON_YOINK("distutils.tests.test_msvc9compiler");
PYTHON_YOINK("distutils.tests.test_msvccompiler");
PYTHON_YOINK("distutils.tests.test_register");
PYTHON_YOINK("distutils.tests.test_sdist");
PYTHON_YOINK("distutils.tests.test_spawn");
PYTHON_YOINK("distutils.tests.test_sysconfig");
PYTHON_YOINK("distutils.tests.test_text_file");
PYTHON_YOINK("distutils.tests.test_unixccompiler");
PYTHON_YOINK("distutils.tests.test_upload");
PYTHON_YOINK("distutils.tests.test_util");
PYTHON_YOINK("distutils.tests.test_version");
PYTHON_YOINK("distutils.tests.test_versionpredicate");
PYTHON_YOINK("distutils.text_file");
PYTHON_YOINK("distutils.unixccompiler");
PYTHON_YOINK("distutils.util");
PYTHON_YOINK("distutils.version");
PYTHON_YOINK("distutils.versionpredicate");
STATIC_YOINK(".python/distutils/command/command_template");
STATIC_YOINK(".python/distutils/tests/Setup.sample");
PYTHON_YOINK("msilib");
PYTHON_YOINK("msilib.schema");
PYTHON_YOINK("msilib.sequence");
PYTHON_YOINK("msilib.text");
#endif

PYTHON_YOINK("encodings");
PYTHON_YOINK("encodings.aliases");
PYTHON_YOINK("encodings.mbcs");
PYTHON_YOINK("encodings.ascii");
PYTHON_YOINK("encodings.idna");
PYTHON_YOINK("encodings.latin_1");
PYTHON_YOINK("encodings.utf_8");
PYTHON_YOINK("encodings.utf_8_sig");
PYTHON_YOINK("encodings.utf_16");
PYTHON_YOINK("encodings.utf_16_be");
PYTHON_YOINK("encodings.utf_16_le");
PYTHON_YOINK("encodings.utf_32");
PYTHON_YOINK("encodings.utf_32_be");
PYTHON_YOINK("encodings.utf_32_le");
PYTHON_YOINK("encodings.uu_codec");
PYTHON_YOINK("encodings.undefined");
PYTHON_YOINK("encodings.hex_codec");
PYTHON_YOINK("encodings.base64_codec");
PYTHON_YOINK("encodings.unicode_escape");
PYTHON_YOINK("encodings.unicode_internal");
PYTHON_YOINK("encodings.raw_unicode_escape");
#if !IsTiny()
PYTHON_YOINK("encodings.zlib_codec");
PYTHON_YOINK("encodings.big5");
PYTHON_YOINK("encodings.big5hkscs");
PYTHON_YOINK("encodings.bz2_codec");
PYTHON_YOINK("encodings.charmap");
PYTHON_YOINK("encodings.cp037");
PYTHON_YOINK("encodings.cp1006");
PYTHON_YOINK("encodings.cp1026");
PYTHON_YOINK("encodings.cp1125");
PYTHON_YOINK("encodings.cp1140");
PYTHON_YOINK("encodings.cp1250");
PYTHON_YOINK("encodings.cp1251");
PYTHON_YOINK("encodings.cp1252");
PYTHON_YOINK("encodings.cp1253");
PYTHON_YOINK("encodings.cp1254");
PYTHON_YOINK("encodings.cp1255");
PYTHON_YOINK("encodings.cp1256");
PYTHON_YOINK("encodings.cp1257");
PYTHON_YOINK("encodings.cp1258");
PYTHON_YOINK("encodings.cp273");
PYTHON_YOINK("encodings.cp424");
PYTHON_YOINK("encodings.cp437");
PYTHON_YOINK("encodings.cp500");
PYTHON_YOINK("encodings.cp65001");
PYTHON_YOINK("encodings.cp720");
PYTHON_YOINK("encodings.cp737");
PYTHON_YOINK("encodings.cp775");
PYTHON_YOINK("encodings.cp850");
PYTHON_YOINK("encodings.cp852");
PYTHON_YOINK("encodings.cp855");
PYTHON_YOINK("encodings.cp856");
PYTHON_YOINK("encodings.cp857");
PYTHON_YOINK("encodings.cp858");
PYTHON_YOINK("encodings.cp860");
PYTHON_YOINK("encodings.cp861");
PYTHON_YOINK("encodings.cp862");
PYTHON_YOINK("encodings.cp863");
PYTHON_YOINK("encodings.cp864");
PYTHON_YOINK("encodings.cp865");
PYTHON_YOINK("encodings.cp866");
PYTHON_YOINK("encodings.cp869");
PYTHON_YOINK("encodings.cp874");
PYTHON_YOINK("encodings.cp875");
PYTHON_YOINK("encodings.cp932");
PYTHON_YOINK("encodings.cp949");
PYTHON_YOINK("encodings.cp950");
PYTHON_YOINK("encodings.euc_jis_2004");
PYTHON_YOINK("encodings.euc_jisx0213");
PYTHON_YOINK("encodings.euc_jp");
PYTHON_YOINK("encodings.euc_kr");
PYTHON_YOINK("encodings.gb18030");
PYTHON_YOINK("encodings.gb2312");
PYTHON_YOINK("encodings.gbk");
PYTHON_YOINK("encodings.hp_roman8");
PYTHON_YOINK("encodings.hz");
PYTHON_YOINK("encodings.iso2022_jp");
PYTHON_YOINK("encodings.iso2022_jp_1");
PYTHON_YOINK("encodings.iso2022_jp_2");
PYTHON_YOINK("encodings.iso2022_jp_2004");
PYTHON_YOINK("encodings.iso2022_jp_3");
PYTHON_YOINK("encodings.iso2022_jp_ext");
PYTHON_YOINK("encodings.iso2022_kr");
PYTHON_YOINK("encodings.iso8859_1");
PYTHON_YOINK("encodings.iso8859_10");
PYTHON_YOINK("encodings.iso8859_11");
PYTHON_YOINK("encodings.iso8859_13");
PYTHON_YOINK("encodings.iso8859_14");
PYTHON_YOINK("encodings.iso8859_15");
PYTHON_YOINK("encodings.iso8859_16");
PYTHON_YOINK("encodings.iso8859_2");
PYTHON_YOINK("encodings.iso8859_3");
PYTHON_YOINK("encodings.iso8859_4");
PYTHON_YOINK("encodings.iso8859_5");
PYTHON_YOINK("encodings.iso8859_6");
PYTHON_YOINK("encodings.iso8859_7");
PYTHON_YOINK("encodings.iso8859_8");
PYTHON_YOINK("encodings.iso8859_9");
PYTHON_YOINK("encodings.johab");
PYTHON_YOINK("encodings.koi8_r");
PYTHON_YOINK("encodings.koi8_t");
PYTHON_YOINK("encodings.koi8_u");
PYTHON_YOINK("encodings.kz1048");
PYTHON_YOINK("encodings.mac_arabic");
PYTHON_YOINK("encodings.mac_centeuro");
PYTHON_YOINK("encodings.mac_croatian");
PYTHON_YOINK("encodings.mac_cyrillic");
PYTHON_YOINK("encodings.mac_farsi");
PYTHON_YOINK("encodings.mac_greek");
PYTHON_YOINK("encodings.mac_iceland");
PYTHON_YOINK("encodings.mac_latin2");
PYTHON_YOINK("encodings.mac_roman");
PYTHON_YOINK("encodings.mac_romanian");
PYTHON_YOINK("encodings.mac_turkish");
PYTHON_YOINK("encodings.oem");
PYTHON_YOINK("encodings.palmos");
PYTHON_YOINK("encodings.ptcp154");
PYTHON_YOINK("encodings.punycode");
PYTHON_YOINK("encodings.quopri_codec");
PYTHON_YOINK("encodings.rot_13");
PYTHON_YOINK("encodings.shift_jis");
PYTHON_YOINK("encodings.shift_jis_2004");
PYTHON_YOINK("encodings.shift_jisx0213");
PYTHON_YOINK("encodings.tis_620");
PYTHON_YOINK("encodings.utf_7");
#endif

#if !IsTiny()
PYTHON_YOINK("smtpd");
PYTHON_YOINK("poplib");
PYTHON_YOINK("imaplib");
PYTHON_YOINK("mailbox");
PYTHON_YOINK("mailcap");
PYTHON_YOINK("smtplib");
PYTHON_YOINK("nntplib");
#endif

#ifdef WITH_THREAD
PYTHON_YOINK("asynchat");
PYTHON_YOINK("asyncore");
PYTHON_YOINK("asyncio");
PYTHON_YOINK("asyncio.base_events");
PYTHON_YOINK("asyncio.base_futures");
PYTHON_YOINK("asyncio.base_subprocess");
PYTHON_YOINK("asyncio.base_tasks");
PYTHON_YOINK("asyncio.compat");
PYTHON_YOINK("asyncio.constants");
PYTHON_YOINK("asyncio.coroutines");
PYTHON_YOINK("asyncio.events");
PYTHON_YOINK("asyncio.futures");
PYTHON_YOINK("asyncio.locks");
PYTHON_YOINK("asyncio.log");
PYTHON_YOINK("asyncio.proactor_events");
PYTHON_YOINK("asyncio.protocols");
PYTHON_YOINK("asyncio.queues");
PYTHON_YOINK("asyncio.selector_events");
PYTHON_YOINK("asyncio.sslproto");
PYTHON_YOINK("asyncio.streams");
PYTHON_YOINK("asyncio.subprocess");
PYTHON_YOINK("asyncio.tasks");
PYTHON_YOINK("asyncio.test_utils");
PYTHON_YOINK("asyncio.transports");
PYTHON_YOINK("asyncio.unix_events");
PYTHON_YOINK("asyncio.windows_events");
PYTHON_YOINK("asyncio.windows_utils");
#endif

const struct _frozen *PyImport_FrozenModules = _PyImport_FrozenModules;
struct _inittab *PyImport_Inittab = _PyImport_Inittab;
static jmp_buf jbuf;

static void
OnKeyboardInterrupt(int sig)
{
    gclongjmp(jbuf, 1);
}

static void
AddCompletion(linenoiseCompletions *c, char *s)
{
    c->cvec = realloc(c->cvec, ++c->len * sizeof(*c->cvec));
    c->cvec[c->len - 1] = s;
}

static void
CompleteDict(const char *b, const char *q, const char *p,
             linenoiseCompletions *c, PyObject *o)
{
    const char *s;
    PyObject *k, *v;
    Py_ssize_t i, m;
    for (i = 0; PyDict_Next(o, &i, &k, &v);) {
        if ((v != Py_None && PyUnicode_Check(k) &&
             (s = PyUnicode_AsUTF8AndSize(k, &m)) &&
             m >= q - p && !memcmp(s, p, q - p))) {
            AddCompletion(c, xasprintf("%.*s%.*s", p - b, b, m, s));
        }
    }
}

static void
CompleteDir(const char *b, const char *q, const char *p,
            linenoiseCompletions *c, PyObject *o)
{
    Py_ssize_t m;
    const char *s;
    PyObject *d, *i, *k;
    if (!(d = PyObject_Dir(o))) return;
    if ((i = PyObject_GetIter(d))) {
        while ((k = PyIter_Next(i))) {
            if (((s = PyUnicode_AsUTF8AndSize(k, &m)) &&
                 m >= q - p && !memcmp(s, p, q - p))) {
                AddCompletion(c, xasprintf("%.*s%.*s", p - b, b, m, s));
            }
            Py_DECREF(k);
        }
        Py_DECREF(i);
    }
    Py_DECREF(d);
}

static void
TerminalCompletion(const char *p, linenoiseCompletions *c)
{
    PyObject *o, *t, *i;
    const char *q, *s, *b;
    for (b = p, p += strlen(p); p > b; --p) {
        if (!isalnum(p[-1]) && p[-1] != '.' && p[-1] != '_') {
            break;
        }
    }
    o = PyModule_GetDict(PyImport_AddModule("__main__"));
    if (!*(q = strchrnul(p, '.'))) {
        CompleteDict(b, q, p, c, o);
        CompleteDir(b, q, p, c, PyDict_GetItemString(o, "__builtins__"));
    } else {
        s = strndup(p, q - p);
        if ((t = PyDict_GetItemString(o, s))) {
            Py_INCREF(t);
        } else {
            o = PyDict_GetItemString(o, "__builtins__");
            if (PyObject_HasAttrString(o, s)) {
                t = PyObject_GetAttrString(o, s);
            }
        }
        while ((p = q + 1), (o = t)) {
            if (*(q = strchrnul(p, '.'))) {
                t = PyObject_GetAttrString(o, gc(strndup(p, q - p)));
                Py_DECREF(o);
            } else {
                CompleteDir(b, q, p, c, o);
                Py_DECREF(o);
                break;
            }
        }
        free(s);
    }
}

static char *
TerminalHint(const char *p, const char **ansi1, const char **ansi2)
{
    char *h = 0;
    linenoiseCompletions c = {0};
    TerminalCompletion(p, &c);
    if (c.len == 1) {
        h = strdup(c.cvec[0] + strlen(p));
    }
    linenoiseFreeCompletions(&c);
    return h;
}

static char *
TerminalReadline(FILE *sys_stdin, FILE *sys_stdout, const char *prompt)
{
    size_t n;
    char *p, *q;
    PyOS_sighandler_t saint;
    saint = PyOS_setsig(SIGINT, OnKeyboardInterrupt);
    if (setjmp(jbuf)) {
        linenoiseDisableRawMode(STDIN_FILENO);
        PyOS_setsig(SIGINT, saint);
        return NULL;
    }
    p = ezlinenoise(prompt, "python");
    PyOS_setsig(SIGINT, saint);
    if (p) {
        n = strlen(p);
        q = PyMem_RawMalloc(n + 2);
        strcpy(mempcpy(q, p, n), "\n");
        free(p);
        clearerr(sys_stdin);
    } else {
        q = PyMem_RawMalloc(1);
        if (q) *q = 0;
    }
    return q;
}

int
main(int argc, char **argv)
{
    wchar_t **argv_copy;
    /* We need a second copy, as Python might modify the first one. */
    wchar_t **argv_copy2;
    int i, res;
    char *oldloc;

    /* if (FindDebugBinary()) { */
    /*     ShowCrashReports(); */
    /* } */

    PyOS_ReadlineFunctionPointer = TerminalReadline;
    linenoiseSetCompletionCallback(TerminalCompletion);
    linenoiseSetHintsCallback(TerminalHint);
    linenoiseSetFreeHintsCallback(free);

    /* Force malloc() allocator to bootstrap Python */
    _PyMem_SetupAllocators("malloc");

    argv_copy = (wchar_t **)PyMem_RawMalloc(sizeof(wchar_t*) * (argc+1));
    argv_copy2 = (wchar_t **)PyMem_RawMalloc(sizeof(wchar_t*) * (argc+1));
    if (!argv_copy || !argv_copy2) {
        fprintf(stderr, "out of memory\n");
        return 1;
    }

    /* 754 requires that FP exceptions run in "no stop" mode by default,
     * and until C vendors implement C99's ways to control FP exceptions,
     * Python requires non-stop mode.  Alas, some platforms enable FP
     * exceptions by default.  Here we disable them.
     */
#ifdef __FreeBSD__
    fedisableexcept(FE_OVERFLOW);
#endif

    oldloc = _PyMem_RawStrdup(setlocale(LC_ALL, NULL));
    if (!oldloc) {
        fprintf(stderr, "out of memory\n");
        return 1;
    }

    setlocale(LC_ALL, "");
    for (i = 0; i < argc; i++) {
        argv_copy[i] = Py_DecodeLocale(argv[i], NULL);
        if (!argv_copy[i]) {
            PyMem_RawFree(oldloc);
            fprintf(stderr, "Fatal Python error: "
                            "unable to decode the command line argument #%i\n",
                            i + 1);
            return 1;
        }
        argv_copy2[i] = argv_copy[i];
    }
    argv_copy2[argc] = argv_copy[argc] = NULL;

    setlocale(LC_ALL, oldloc);
    PyMem_RawFree(oldloc);

    res = Py_Main(argc, argv_copy);

    /* Force again malloc() allocator to release memory blocks allocated
       before Py_Main() */
    _PyMem_SetupAllocators("malloc");

    for (i = 0; i < argc; i++) {
        PyMem_RawFree(argv_copy2[i]);
    }
    PyMem_RawFree(argv_copy);
    PyMem_RawFree(argv_copy2);
    return res;
}
