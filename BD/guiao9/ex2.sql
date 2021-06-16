--CREATE TABLE mytemp (
--	rid BIGINT IDENTITY (1, 1) NOT NULL,
--	at1 INT NULL,
--	at2 INT NULL,
--	at3 INT NULL,
--	lixo varchar(100) NULL
--	PRIMARY KEY(rid)
--	);




--CREATE CLUSTERED INDEX Rid ON mytemp(rid);
--DROP INDEX Rid on mytemp
--Create clustered index rid on mytemp(rid) with (FILLFACTOR = 65)
--drop index rid on mytemp
--Create clustered index rid on mytemp(rid) with (FILLFACTOR = 80)
--drop index rid on mytemp
--Create clustered index rid on mytemp(rid) with (FILLFACTOR = 90)
--DROP INDEX rid ON mytemp

--CREATE INDEX rid on mytemp(rid);
--CREATE INDEX at1 on mytemp(at1)
--CREATE INDEX at2 on mytemp(at2)
--CREATE INDEX at3 on mytemp(at3)
--CREATE INDEX lixo on mytemp(lixo)
--DROP INDEX rid ON mytemp
--DROP INDEX at1 ON mytemp
--DROP INDEX at2 ON mytemp
--DROP INDEX at3 ON mytemp
--DROP INDEX lixo ON mytemp

-- Record the Start Time
DECLARE @start_time2 DATETIME, @end_time2 DATETIME;
SET IDENTITY_INSERT mytemp ON
SET @start_time2 = GETDATE();
PRINT @start_time2
-- Generate random records
DECLARE @val2 as int = 1;
DECLARE @nelem2 as int = 50000;
SET nocount ON
WHILE @val2 <= @nelem2
BEGIN
DBCC DROPCLEANBUFFERS; -- need to be sysadmin
INSERT mytemp (rid, at1, at2, at3, lixo)
SELECT cast((RAND()*@nelem2*40000) as int), cast((RAND()*@nelem2) as int),
cast((RAND()*@nelem2) as int), cast((RAND()*@nelem2) as int),
'lixo...lixo...lixo...lixo...lixo...lixo...lixo...lixo...lixo';
SET @val2 = @val2 + 1;
END
PRINT 'Inserted ' + str(@nelem2) + ' total records'
-- Duration of Insertion Process
SET @end_time2 = GETDATE();
PRINT 'Milliseconds used: ' + CONVERT(VARCHAR(20), DATEDIFF(MILLISECOND,
@start_time2, @end_time2));
SELECT avg(avg_fragmentation_in_percent) as avg_frag, avg(avg_page_space_used_in_percent) as avg_page_sp FROM sys.dm_db_index_physical_stats (db_id('mytemp'), object_id('FRAG'),NULL,NULL,'DETAILED');
