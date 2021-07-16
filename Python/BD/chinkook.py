from os import name
import sqlite3
from sqlite3 import Error
from sqlite3.dbapi2 import register_converter


def create_connection(db_file):
    """Create a DB connection to SQLite database specified by db_file

    :param db_file path of the file
    :return: Connection object or None
    """

    conn = None
    try:
        conn = sqlite3.connect(db_file)
        print(sqlite3.version)
    except Error as e:
        print(e)

    return conn


def create_table(conn, create_table_sql_query):
    """create a table from the create_table_sql statement
    :param conn: Connection object
    :param create_table_sql: a Create Table statment
    :return:"""

    try:
        c = conn.cursor()
        c.execute(create_table_sql_query)
    except Error as e:
        print(e)


def insert_into_table(conn, name_table, insert_query):
    """
    Create a new project into the projects table
    :param conn:
    :param name_table:
    :param insert_query:
    :return: last id assigned
    """
    try:
        sql = ''' INSERT INTO {name_table}(name,begin_date,end_date)
              VALUES(?,?,?) '''
        cur = conn.cursor()
        cur.execute(sql, insert_query)
        conn.commit()
    except Exception as e:
        return False

    return cur.lastrowid


def update_table(conn, task):
    """
    :param conn:
    :param task:
    :return: project id
    """
    sql = ''' UPDATE tasks
              SET priority = ? ,
                  begin_date = ? ,
                  end_date = ?
              WHERE id = ?'''
    cur = conn.cursor()
    cur.execute(sql, task)
    conn.commit()


def delete_by_id(conn, name_table, id):
    """
    Delete a task by task id
    :param conn:  Connection to the SQLite database
    :param name_table:
    :param id: id of the task
    :return:
    """
    sql = 'DELETE FROM {name_table} WHERE id=?'
    cur = conn.cursor()
    cur.execute(sql, (id,))
    conn.commit()


def delete_all_from_table(conn, name_table):
    """
    Delete all rows in the tasks table
    :param conn: Connection to the SQLite database
    :name_table: Name of the table you want to delet
    :return:
    """
    sql = f'DELETE FROM {name_table}'
    cur = conn.cursor()
    cur.execute(sql)
    conn.commit()


def select_all_from_table(conn, name_table):
    """
    Query all rows in the tasks table
    :param conn: the Connection object
    :param name_table: Name of the table
    :return:
    """
    cur = conn.cursor()
    cur.execute(f"SELECT * FROM {name_table}")

    rows = cur.fetchall()

    for row in rows:
        print(row)


def select_all_by_priority(conn, name_table, priority):
    """
    Query tasks by priority
    :param conn: the Connection object
    :param priority:
    :name_table:
    :return:
    """
    cur = conn.cursor()
    cur.execute(f"SELECT * FROM {name_table} WHERE priority=?", (priority,))

    rows = cur.fetchall()

    for row in rows:
        print(row)


def main():
    database = r"C:\sqlite\db\pythonsqlite.db"

    # create a database connection
    conn = create_connection(database)
    with conn:
        print("1. Query task by priority:")
        select_task_by_priority(conn, 1)

        print("2. Query all tasks")
        select_all_tasks(conn)


if __name__ == '__main__':
    # create_connection(r"C:\sqlite\chinook.db")
    main()
    pass
