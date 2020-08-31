CREATE TABLE [Calls]
(
    [ClientId] INTEGER NOT NULL,
    [IncomingNumber] NVARCHAR(24),
	[FirstCallDate] DATE NOT NULL,
	[AvgCallDuration] INTEGER NOT NULL
);

CREATE TABLE [Clients_CRM]
(
    [ClientId] INTEGER NOT NULL,
    [CreationDate] DATE	NOT NULL,
	[FirstName] NVARCHAR(40) NOT NULL,
    [LastName] NVARCHAR(30) NOT NULL,
    [Phone] NVARCHAR(24)
);

