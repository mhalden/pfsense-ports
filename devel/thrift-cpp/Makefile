# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION} # to keep in sync with thrift
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE/thrift/${PORTVERSION}
PKGNAMESUFFIX=	-cpp
DISTNAME=	thrift-${PORTVERSION}

MAINTAINER=	komarov@valerka.net
COMMENT=	C++ interface to Thrift

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libevent.so:devel/libevent

DISTINFO_FILE=		${.CURDIR}/../thrift/distinfo

BROKEN_powerpc64=	fails to compile: undefined reference to std::__throw_out_of_range_fmt
BROKEN_SSL=	openssl-devel
BROKEN_SSL_REASON_openssl-devel=	'configure: error: "Error: libcrypto required."'

USES=			autoreconf pkgconfig gmake compiler:c++11-lang \
			libtool pathfix ssl
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes
MAKE_JOBS_UNSAFE=	yes
PLIST_SUB=		PORTVERSION="${THRIFT_PORTVERSION}"

OPTIONS_DEFINE=		QT4
QT4_CONFIGURE_WITH=	qt4
QT4_USES=		qt:4
QT4_USE=		QT=network,moc_build,qmake_build,rcc_build,uic_build

OPTIONS_SUB=		yes

CONFIGURE_ARGS+=	\
		--without-c_glib \
		--with-cpp \
		--with-boost-libdir="${LOCALBASE}/lib" \
		--without-csharp \
		--without-erlang \
		--without-haskell \
		--without-java \
		--without-perl \
		--without-php \
		--without-php_extension \
		--without-python \
		--without-ruby \
		--without-go

LDFLAGS+=	-L${OPENSSLLIB}
CFLAGS+=	-I${OPENSSLINC}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
USE_CXXSTD=	c++11
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so
	${LN} -sf libthrift-${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib/libthrift.so.0
	${LN} -sf libthriftnb-${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib/libthriftnb.so.0
	${LN} -sf libthriftz-${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib/libthriftz.so.0

post-install-QT4-on:
	${LN} -sf libthriftqt-${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib/libthriftqt.so.0

.include "../thrift/bsd.thrift.mk"
.include <bsd.port.post.mk>
