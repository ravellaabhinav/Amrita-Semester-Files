const { BlobServiceClient } = require("@azure/storage-blob");

async function main() {

  blobServiceClient = new BlobServiceClient("https://cloud453.blob.core.windows.net/?sv=2020-08-04&ss=bfqt&srt=sco&sp=rwdlacupitfx&se=2022-02-22T18:45:08Z&st=2022-02-22T10:45:08Z&spr=https&sig=zhSjetrk8QsSS7gScswKxulolnoYjHTqbgCSSgefkWY%3D");

  // Create a container
  const containerName = `mysamplecontainer19453`;
  const containerClient = blobServiceClient.getContainerClient(containerName);
  const createContainerResponse = await containerClient.create();

  // get all containers
  let i = 1;
  let containers = blobServiceClient.listContainers();
  for await (const container of containers) {
    console.log(`${container.name}`);
  }


  // upload image 
  const blockBlobClient = containerClient.getBlockBlobClient("image.png");
  const uploadBlobResponse = await blockBlobClient.uploadFile('C:\\Users\\Administrator\\Downloads\\cloudimg1.png');

  // get all blobs
  i = 1;
  let blobs = containerClient.listBlobsFlat();
  for await (const blob of blobs) {
    console.log(`${blob.name}`);
  }

}

main();