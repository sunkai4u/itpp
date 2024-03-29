Name:           itpp
Version:        4.2
Release:        1
Summary:        C++ library of math, signal/speech processing and communications

Group:          System Environment/Libraries
License:        GPL
URL:            http://itpp.sourceforge.net/
Source:         http://download.sourceforge.net/itpp/%{name}-%{version}.tar.bz2
Packager:       Adam Piatyszek <ediap@users.sourceforge.net>
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-buildroot

Prereq:         /sbin/ldconfig
#BuildRequires:  fftw-devel

%description
IT++ is a C++ library of mathematical, signal processing, speech
processing, and communications classes and functions.  The kernel of
the IT++ library is built upon templated vector and matrix classes
with many functions for their manipulation.  Such a kernel makes IT++
similar to Octave.  IT++ makes extensive use of existing open-source
libraries (but not only) for increased functionality, speed, and
accuracy.

%package doc
Summary:        HTML documentation for itpp
Group:          System Environment/Libraries
Requires:       %{name} = %{version}-%{release}

%description doc
This package contains the IT++ reference documentation in the HTML format.


%prep
%setup -q


%build
%configure --with-docdir=%{_docdir}/%{name}-%{version}
make


%install
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/%{_docdir}/%{name}-%{version}
cp -p AUTHORS ChangeLog ChangeLog-2005 ChangeLog-2006 INSTALL NEWS \
  NEWS-3.10 NEWS-3.9 NEWS-3.99 README \
  $RPM_BUILD_ROOT/%{_docdir}/%{name}-%{version}


%clean
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT

%post
/sbin/ldconfig

%postun
/sbin/ldconfig

%files
%defattr(-,root,root,-)
%{_docdir}/%{name}-%{version}/[A-Z]*
%{_libdir}/*.la
%{_libdir}/*.a
%{_libdir}/*.so
%{_libdir}/*.so.*
%{_libdir}/pkgconfig/%{name}.pc
%{_bindir}/%{name}-config
%{_includedir}/%{name}
%{_datadir}/%{name}

%files doc
%defattr(-,root,root,-)
%{_docdir}/%{name}-%{version}/html

%changelog
* Tue Apr  4 2007  Adam Piatyszek  <ediap@users.sourceforge.net>
- Minor cleanups and changes according to the latest itpp.spec from
  Fedora Extras

* Mon Feb 13 2006  Adam Piatyszek  <ediap@users.sourceforge.net>
- Created subpackage itpp-html-doc with HTML documentation

* Fri Feb 10 2006  Adam Piatyszek  <ediap@users.sourceforge.net>
- Added missing *.a and *.m files

* Thu Feb 09 2006  Adam Piatyszek  <ediap@users.sourceforge.net>
- Changes in Name, Version and Release definitions
- Removed distribution dependent release settings
- Added DESTDIR to make install command

* Wed Dec 28 2005  Adam Piatyszek  <ediap@users.sourceforge.net>
- Fixed name and version definitions
- Added itpp-config in %files section

* Fri Dec 23 2005  Adam Piatyszek  <ediap@users.sourceforge.net>
- Initial spec file prepared
