# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qbittorrent
DISTVERSION=	4.1.3
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bittorrent client using Qt4/5 and libtorrent-rasterbar

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_10=	error: no matching constructor for initialization of 'const QString'

LIB_DEPENDS=	libtorrent-rasterbar.so:net-p2p/libtorrent-rasterbar \
		libboost_system.so:devel/boost-libs

FLAVORS=	default nox
FLAVOR?=	${FLAVORS:[1]}
default_LIB_DEPENDS=	libGeoIP.so:net/GeoIP
nox_PKGNAMESUFFIX=	-nox
nox_PLIST=		${NONEXISTENT}

USES=			compiler:c++11-lib pkgconfig qmake:no_env qt:5 tar:xz
GNU_CONFIGURE=		yes
USE_QT=			core network xml buildtools_build linguisttools_build qmake_build
CONFIGURE_ARGS=		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"
DESTDIRNAME=		INSTALL_ROOT

.if ${FLAVOR} == default
USES+=			desktop-file-utils
USE_QT+=		concurrent gui svg widgets
USE_GL=			gl
.endif

.if ${FLAVOR} == nox
SUFFIX=			-nox
COMMENT+=		(web UI version)
CONFIGURE_ARGS+=	--disable-gui
PLIST_FILES=		bin/qbittorrent${SUFFIX} \
			man/man1/qbittorrent${SUFFIX}.1.gz
.endif

OPTIONS_DEFINE=		DBUS DEBUG DOCS
OPTIONS_DEFAULT=	DBUS

DEBUG_CONFIGURE_ENABLE=	debug
DBUS_CONFIGURE_ENABLE=	qt-dbus
DBUS_USE=		qt=dbus

PORTDOCS=		AUTHORS Changelog README.md

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qbittorrent${SUFFIX}
	${INSTALL_MAN} ${WRKSRC}/doc/qbittorrent${SUFFIX}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/
	@${RM} -r ${STAGEDIR}${PREFIX}/share/man

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
