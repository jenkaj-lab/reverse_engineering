The **CryptGenKey** function generates a random cryptographic [session key](https://learn.microsoft.com/en-us/windows/desktop/SecGloss/s-gly) or a [public/private key pair](https://learn.microsoft.com/en-us/windows/desktop/SecGloss/p-gly). A handle to the key or key pair is returned in _phKey_. This handle can then be used as needed with any CryptoAPI function that requires a key handle.

The calling application must specify the algorithm when calling this function. Because this algorithm type is kept bundled with the key, the application does not need to specify the algorithm later when the actual cryptographic operations are performed.

Reference:
https://learn.microsoft.com/en-us/windows/win32/api/wincrypt/nf-wincrypt-cryptgenkey