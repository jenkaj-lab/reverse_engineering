Retrieves information about MS-DOS device names. The function can obtain the current mapping for a particular MS-DOS device name. The function can also obtain a list of all existing MS-DOS device names.

MS-DOS device names are stored as junctions in the object namespace. The code that converts an MS-DOS path into a corresponding path uses these junctions to map MS-DOS devices and drive letters. The **QueryDosDevice** function enables an application to query the names of the junctions used to implement the MS-DOS device namespace as well as the value of each specific junction.

Reference:
https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-querydosdevicew