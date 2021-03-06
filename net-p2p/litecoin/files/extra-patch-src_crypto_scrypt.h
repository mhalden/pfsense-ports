--- src/crypto/scrypt.h.orig	2018-05-23 11:31:01.662350000 -0400
+++ src/crypto/scrypt.h	2018-05-23 11:31:25.771775000 -0400
@@ -28,21 +28,4 @@ void
 PBKDF2_SHA256(const uint8_t *passwd, size_t passwdlen, const uint8_t *salt,
     size_t saltlen, uint64_t c, uint8_t *buf, size_t dkLen);
 
-#ifndef __FreeBSD__
-static inline uint32_t le32dec(const void *pp)
-{
-        const uint8_t *p = (uint8_t const *)pp;
-        return ((uint32_t)(p[0]) + ((uint32_t)(p[1]) << 8) +
-            ((uint32_t)(p[2]) << 16) + ((uint32_t)(p[3]) << 24));
-}
-
-static inline void le32enc(void *pp, uint32_t x)
-{
-        uint8_t *p = (uint8_t *)pp;
-        p[0] = x & 0xff;
-        p[1] = (x >> 8) & 0xff;
-        p[2] = (x >> 16) & 0xff;
-        p[3] = (x >> 24) & 0xff;
-}
-#endif
 #endif
