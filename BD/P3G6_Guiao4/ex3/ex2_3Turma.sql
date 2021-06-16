/*CREATE SCHEMA ATL;


CREATE TABLE ATL.PESSOA(
	CC		INT				NOT NULL,
	NOME	VARCHAR(30)		,
	MORADA	VARCHAR(30)		,
	DATANASC	DATE		,
	PRIMARY KEY(CC));

CREATE TABLE ATL.ADULTO(
	CC			INT			NOT NULL,
	EMAIL		VARCHAR(30)	,
	CONTACTO	INT			,
	PRIMARY KEY(CC),
	FOREIGN KEY (CC) REFERENCES ATL.PESSOA(CC));


CREATE TABLE ATL.PESAUT(
	CC INT NOT NULL,
	PRIMARY KEY (CC),
	FOREIGN KEY (CC) REFERENCES ATL.ADULTO(CC));
		

CREATE TABLE ATL.ENC_EDUC(
	CC INT NOT NULL,
	PRIMARY KEY (CC),
	FOREIGN KEY (CC) REFERENCES ATL.ADULTO(CC));


CREATE TABLE ATL.TURMA(
	ID			INT			NOT NULL,
	DESIGNACAO	VARCHAR(30)		NOT NULL,
	ANO			INT			NOT NULL,
	MAX_ALUNOS	INT,
	PRIMARY KEY (ID));


CREATE TABLE ATL.PROFESSOR (
	CC			INT		NOT NULL,
	NFUNC		INT		NOT NULL,
	FK_TURMA	INT		NOT NULL,
	PRIMARY KEY(CC, NFUNC),
	FOREIGN KEY (FK_TURMA) REFERENCES ATL.TURMA(ID));

CREATE TABLE ATL.ESCOLARIDADE (
	ESCOLARIDADE	BINARY(3)	NOT NULL,
	FK_TURMA		INT			NOT NULL,
	PRIMARY KEY(ESCOLARIDADE),
	FOREIGN KEY(FK_TURMA) REFERENCES ATL.TURMA(ID));


CREATE TABLE ATL.ATIVIDADES (
	DESIGNACAO		VARCHAR(30)		,
	ID				INT				NOT NULL,
	CUSTO			INT				,
	FREQ			INT				,
	PRIMARY KEY (ID));

CREATE TABLE ATL.TTEMACT(
	ACTID		INT		NOT NULL,
	TID			INT		NOT NULL,
	PRIMARY KEY (ACTID, TID),
	FOREIGN KEY (ACTID) REFERENCES ATL.ATIVIDADES(ID),
	FOREIGN KEY (TID) REFERENCES ATL.TURMA(ID));

CREATE TABLE ATL.ALUNO (
	CC			INT		NOT NULL,
	FK_PA		INT		NOT NULL,
	FK_EE		INT		NOT NULL,
	FK_TURMA	INT		NOT NULL,
	PRIMARY KEY (CC),
	FOREIGN KEY (CC) REFERENCES ATL.PESSOA(CC),
	FOREIGN KEY (FK_PA) REFERENCES ATL.PESAUT(CC),
	FOREIGN KEY (FK_EE) REFERENCES ATL.ENC_EDUC(CC),
	FOREIGN KEY (FK_TURMA) REFERENCES ATL.TURMA(ID));

CREATE TABLE ATL.ALUVAIAT(
	ACTID		INT		NOT NULL,
	ALUCC			INT		NOT NULL,
	PRIMARY KEY (ACTID, ALUCC),
	FOREIGN KEY (ACTID) REFERENCES ATL.ATIVIDADES(ID),
	FOREIGN KEY (ALUCC) REFERENCES ATL.ALUNO(CC));

*/
