import sqlalchemy as db
import pymysql
import pandas as pd
import sys

def insercion():
    pathExcel = sys.argv[1]
    nameDataBase = sys.argv[2]
    dataBase = sys.argv[3]
    usr = 'Alonso'
    psw = '.TEKP!bida5NzPc'

    engine = db.create_engine(f"mysql+pymysql://{usr}:{psw}@localhost/{dataBase}")
    connection = engine.connect()
    contactos=pd.read_excel(pathExcel)

    try:
        contactos.to_sql(nameDataBase, engine)
    except Exception as e:
        raise Exception('Hubo un error en la insersion de datos... ',e)
    else:
        connection.close()
        engine.dispose()
        print(f"Insertado correctamente a {dataBase} con el nombre de {nameDataBase}")

if __name__ == '__main__':
    insercion()