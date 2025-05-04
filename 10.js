const { MongoClient } = require('mongodb');
const uri = 'mongodb://127.0.0.1:27017';
const client = new MongoClient(uri);
const dbname = 'mydatabase';
const collectionname = 'mycollection'

async function createDocument() {
    try {
        await client.connect();
        const collection = client.db(dbname).collection(collectionname);

        await collection.insertOne({
            name: 'John',
            age: 30,
            city: 'New York'
        })
    } catch (error) {
        console.log(error);

    } finally {
        client.close();
    }
}

async function updateOne() {
    try {
        client.connect();
        const collection = client.db(dbname).collection(collectionname);
        await collection.updateMany({ name: John }, { $set: 35 })
    } catch (error) {
        console.log(error);
    } finally {
        client.close();
    }
}

async function deleteDocuments() {
    try {
        client.connect();
        const collection = client.db(dbname).collection(collectionname);

    } catch (error) {
        console.log(error);

    } finally {
        clearInterval.close();
    }
}