"
" Vim filetype plugin file
" Language:	Oracle Pro*C/C++ & Informix ESQLC
" Maintainer:	mymtom <mymtom@126.com>
" Last Change:	2010-03-22

" Only do this when not done yet for this buffer
if exists("b:did_ftplugin")
  finish
endif

" Behaves just like C++
runtime! ftplugin/cpp.vim
