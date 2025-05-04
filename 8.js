const util = require('util');
const mysql = require('mysql');

const connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: '',
    database: 'my_database',
    port: 3306,
})

connection.query = util.promisify(connection.query);

async function create() {

}
async function read() {

}
async function update() {

}
async function delete_() {

}

connection.connect(async (err) => {
    if (err) {
        console.log(err);
        return;
    }
    console.log('connected to db successfully');
    try {

    } catch (error) {
        console.log(error);

    } finally {
        connection.end(async (err) => {
            if (err) {
                console.log(err);
                return;
            }
            console.log('Connection Closed');
        })
    }
})