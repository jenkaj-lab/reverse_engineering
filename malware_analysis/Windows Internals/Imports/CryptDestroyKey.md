The **CryptDestroyKey** function releases the handle referenced by the _hKey_ parameter. After a key handle has been released, it is no longer valid and cannot be used again.

If the handle refers to a session key, or to a public key that has been imported into the [cryptographic service provider](https://learn.microsoft.com/en-us/windows/desktop/SecGloss/c-gly) (CSP) through [CryptImportKey](https://learn.microsoft.com/en-us/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey), this function destroys the key and frees the memory that the key used. Many CSPs overwrite the memory where the key was held before freeing it. However, the underlying [public/private key pair](https://learn.microsoft.com/en-us/windows/desktop/SecGloss/p-gly) is not destroyed by this function. Only the handle is destroyed.

Reference:
https://learn.microsoft.com/en-us/windows/win32/api/wincrypt/nf-wincrypt-cryptdestroykey