DBCC FREEPROCCACHE;
DBCC DROPCLEANBUFFERS;
go
--select * from Production.WorkOrder
--select * from Production.WorkOrder where WorkOrderID=1234
--SELECT * FROM Production.WorkOrder
--WHERE WorkOrderID between 10000 and 10010
--SELECT * FROM Production.WorkOrder
--WHERE WorkOrderID between 1 and 72591
--SELECT * FROM Production.WorkOrder
--WHERE StartDate = '2007-06-25'
--SELECT * FROM Production.WorkOrder WHERE ProductID = 757
--SELECT WorkOrderID, StartDate FROM Production.WorkOrder
--WHERE ProductID = 757
--SELECT WorkOrderID, StartDate FROM Production.WorkOrder
--WHERE ProductID = 945
--SELECT WorkOrderID FROM Production.WorkOrder
--WHERE ProductID = 945 AND StartDate = '2006-01-04'
--SELECT WorkOrderID, StartDate FROM Production.WorkOrder
--WHERE ProductID = 945 AND StartDate = '2006-01-04'
SELECT WorkOrderID, StartDate FROM Production.WorkOrder
WHERE ProductID = 945 AND StartDate = '2006-01-04'
go

--CREATE INDEX ProductID on Production.WorkOrder(ProductID);
--CREATE INDEX PRODUCTID on Production.WorkOrder(ProductID) INClUDE (StartDate)
--DROP INDEX PRODUCTID on Production.WorkOrder
--DROP INDEX ProductID on Production.WorkOrder;
--DROP INDEX IX_WorkOrder_ProductID on Production.WorkOrder;
--DROP INDEX IX_WorkOrder_ScrapReasonID on Production.WorkOrder;
--CREATE INDEX ProductID ON Production.WorkOrder(ProductID)
--CREATE INDEX StartDate ON Production.WorkOrder(StartDate)
--DROP INDEX ProductID ON Production.WorkOrder
--DROP INDEX StartDate ON Production.WorkOrder
CREATE INDEX Composite ON Production.WorkOrder(ProductID, StartDate)
