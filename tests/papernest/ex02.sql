/* First, I would create a fact table like so: */

CREATE TABLE [Customers]
(
    [CustomerId] INT PRIMARY KEY NOT NULL,
	/*Contracts table - FOREIGN KEY*/
	/*Suppliers table - FOREIGN KEY*/
	[FirstName] NVARCHAR(40) NOT NULL,
    [Surname] NVARCHAR(30) NOT NULL,
	[Address] NVARCHAR(50) NOT NULL,
    [StartDate] DATE NOT NULL,
);

/* Then I'd create two additional dimension tables, one for the contracts and one for the suppliers: */

CREATE TABLE [Contracts]
(
    [CustomerId] INT PRIMARY KEY NOT NULL,
	[Contract] NVARCHAR(50) NOT NULL,
);

CREATE TABLE [Suppliers]
(
    [CustomerId] INT PRIMARY KEY NOT NULL,
	[Supplier] NVARCHAR(40) NOT NULL,
);

/* I know dimension tables are linked to the fact table through the fact that they are foreign keys of said table but do not entirely grasp yet how to do it.
My apologies for the incompleteness of that last exercise. Thank you for reading ! */

