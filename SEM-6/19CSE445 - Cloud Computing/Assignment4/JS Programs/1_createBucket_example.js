// Imports the Google Cloud client library
/*const {Storage} = require('@google-cloud/storage');


const storage = new Storage({keyFilename: 'cse445-335504-a7e7476db6bb.json'});

const bucketName = 'gowth12345';

async function createBucket() {
  // Creates the new bucket
  await storage.createBucket(bucketName);
  console.log(`Bucket ${bucketName} created.`);
}


createBucket().catch(console.error);
*/
const { DefaultAzureCredential } = require("@azure/identity");
const { BlobServiceClient } = require("@azure/storage-blob");

// Enter your storage account name
const account = "cloud453";
const defaultAzureCredential = new DefaultAzureCredential();

const blobServiceClient = new BlobServiceClient(
    `https://$cloud453.blob.core.windows.net`,
    defaultAzureCredential
);
console.log('Success');
