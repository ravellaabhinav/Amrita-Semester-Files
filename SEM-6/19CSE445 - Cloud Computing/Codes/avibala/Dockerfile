FROM node:8


COPY server.js /usr/src/app/server.js
WORKDIR /usr/src/app

RUN npm install mysql
RUN npm install http
RUN npm install url
RUN npm install zipcodes
RUN npm install @google-cloud/storage


EXPOSE 9001
CMD [ "node", "server.js" ]
