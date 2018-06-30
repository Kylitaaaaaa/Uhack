import sqlite3
from sqlite3 import Error
import serial
import datetime


def create_connection(db_file):
    """ create a database connection to the SQLite database
        specified by the db_file
    :param db_file: database file
    :return: Connection object or None
    """
    try:
        conn = sqlite3.connect(db_file)
        return conn
    except Error as e:
        print(e)

    return None


def select_all_tasks(conn):
    """
    Query all rows in the tasks table
    :param conn: the Connection object
    :return:
    """
    cur = conn.cursor()
    cur.execute("SELECT * FROM adaptivetraff_stoplight")

    rows = cur.fetchall()

    for row in rows:
        print(row)

def insert_data(conn, data):
    """
    Create a new project into the projects table
    :param conn:
    :param project:
    :return: project id
    """
    sql = ''' INSERT INTO adaptivetraff_stoplight(trafficLoad, colorPhase)
              VALUES(?,?) '''
    cur = conn.cursor()
    cur.execute(sql, data)
    return cur.lastrowid


def main():
    database = "C:/Users/jason_000/Documents/Term 2 17-18/iot/anemometer/db.sqlite3"
    count = 0
    # create a database connection
    conn = create_connection(database)

    count = 0
    serport = serial.Serial('COM6', 9600)
    while (count < 100):
        count += 1
        load = serport.readline()
        load = ''.join(c for c in str(load) if c not in ':<abcdefghijklnopqrtuvwxyz/\\\'ABCDEFGHIJKLMNOPQRSTUVWXYZ ')

        stoplightID = "1234";
        location = "P.Ocampo st."
        colorPhase = "Green"
        data = [stoplightID, location, load, colorPhase]
        insert_data(conn, data)


        print("Traffic Load: ", load)
        print()
        conn.commit()

    conn.close()


if __name__ == '__main__':
    main()