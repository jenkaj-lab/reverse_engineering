## Purpose
From Microsoft: "An access token contains the security information for a logon session. The system creates an access token when a user logs on, and every process executed on behalf of the user has a copy of the token. The token identifies the user, the user's groups, and the user's privileges. The system uses the token to control access to securable objects and to control the ability of the user to perform various system-related operations on the local computer. There are two kinds of access token, primary and impersonation."

## Abuse
The most common method of abuse is [[Access Token Manipulation]], a well-documented MITRE ATT&CK technique where actors may attempt to steal tokens of already logged-on privileged users, create new logon sessions with stolen credentials, or elevate administrator level tokens to gain SYSTEM level privileges.

References:
- https://learn.microsoft.com/en-us/windows/win32/secgloss/a-gly
- https://attack.mitre.org/techniques/T1134/
- https://www.elastic.co/blog/how-attackers-abuse-access-token-manipulation