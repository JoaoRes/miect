/*CREATE SCHEMA CONSULTORIO;

CREATE TABLE CONSULTORIO.PACIENTE(
	NUTENTE		INT				NOT NULL,
	NOME		VARCHAR(30),
	ENDERECO	VARCHAR(30),
	DNASCIMENTO	DATE,
	PRIMARY KEY (NUTENTE));


CREATE TABLE CONSULTORIO.MEDICO(
	SNSID			INT				NOT NULL,
	NOME			VARCHAR(30),
	ESPECIALIDADE	VARCHAR(30)		NOT NULL,
	PRIMARY KEY (SNSID));


CREATE TABLE CONSULTORIO.FARMACIA(
	NIF					INT					NOT NULL,
	NOME				VARCHAR(30),
	ENDERECO			VARCHAR(30),
	TELEFONE			INT,
	FARM_DATAPROCESS	DATE				NOT NULL,
	PRIMARY KEY (NIF));


CREATE TABLE CONSULTORIO.PRESCRICACAO(
	NUNICO		INT		NOT NULL,
	DATA		DATE	,
	FK_PACIENTE	INT		NOT NULL,
	FK_MEDICO	INT		NOT NULL,
	FK_FARMACIA	INT		NOT NULL,
	PRIMARY KEY (NUNICO),
	FOREIGN KEY (FK_PACIENTE) REFERENCES CONSULTORIO.PACIENTE (NUTENTE),
	FOREIGN KEY (FK_MEDICO) REFERENCES CONSULTORIO.MEDICO (SNSID),
	FOREIGN KEY (FK_FARMACIA) REFERENCES CONSULTORIO.FARMACIA (NIF));


CREATE TABLE CONSULTORIO.FARMACEUTICA(
	NNACIONAL		INT				NOT NULL,
	NOME			VARCHAR(30)		,
	ENDERECO		VARCHAR(30)		,
	TELEFONE		INT				,
	PRIMARY KEY (NNACIONAL));


CREATE TABLE CONSULTORIO.FARMACO(
	FORMULA			VARCHAR(30)			NOT NULL,
	NOME			VARCHAR(30),
	FK_FARMACEUTICA	INT					NOT NULL,
	PRIMARY KEY (FORMULA),
	FOREIGN KEY (FK_FARMACEUTICA) REFERENCES CONSULTORIO.FARMACEUTICA(NNACIONAL));



CREATE TABLE CONSULTORIO.VENDE(
	FAR_FORMULA		VARCHAR(30)		NOT NULL,
	FARMACIA_NIF	INT				NOT NULL,
	PRIMARY KEY (FAR_FORMULA, FARMACIA_NIF),
	FOREIGN KEY (FAR_FORMULA) REFERENCES CONSULTORIO.FARMACO(FORMULA),
	FOREIGN KEY	(FARMACIA_NIF) REFERENCES CONSULTORIO.FARMACIA(NIF));
		*/

CREATE TABLE CONSULTORIO.TEM(
	FAR_FORMULA		VARCHAR(30)		NOT NULL,
	PRES_NUNICO		INT				NOT NULL,
	PRIMARY KEY (FAR_FORMULA,PRES_NUNICO),
	FOREIGN KEY (FAR_FORMULA) REFERENCES CONSULTORIO.FARMACO(FORMULA),
	FOREIGN KEY (PRES_NUNICO) REFERENCES CONSULTORIO.PRESCRICACAO(NUNICO));