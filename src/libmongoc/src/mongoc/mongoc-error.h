/*
 * Copyright 2013 MongoDB, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mongoc-prelude.h"

#ifndef MONGOC_ERRORS_H
#define MONGOC_ERRORS_H

#include <bson/bson.h>

#include "mongoc-macros.h"

#define MONGOC_ERROR_API_VERSION_LEGACY 1
#define MONGOC_ERROR_API_VERSION_2 2

BSON_BEGIN_DECLS


typedef enum {
   MONGOC_ERROR_CLIENT = 1,
   MONGOC_ERROR_STREAM,
   MONGOC_ERROR_PROTOCOL,
   MONGOC_ERROR_CURSOR,
   MONGOC_ERROR_QUERY,
   MONGOC_ERROR_INSERT,
   MONGOC_ERROR_SASL,
   MONGOC_ERROR_BSON,
   MONGOC_ERROR_MATCHER,
   MONGOC_ERROR_NAMESPACE,
   MONGOC_ERROR_COMMAND,
   MONGOC_ERROR_COLLECTION,
   MONGOC_ERROR_GRIDFS,
   MONGOC_ERROR_SCRAM,
   MONGOC_ERROR_SERVER_SELECTION,
   MONGOC_ERROR_WRITE_CONCERN,
   MONGOC_ERROR_SERVER, /* Error API Version 2 only */
   MONGOC_ERROR_TRANSACTION,
   MONGOC_ERROR_CLIENT_SIDE_ENCRYPTION, /* An error coming from libmongocrypt */
   MONGOC_ERROR_POOL,
   MONGOC_ERROR_AZURE,
} mongoc_error_domain_t;


typedef enum {
   MONGOC_ERROR_STREAM_INVALID_TYPE = 1,
   MONGOC_ERROR_STREAM_INVALID_STATE,
   MONGOC_ERROR_STREAM_NAME_RESOLUTION,
   MONGOC_ERROR_STREAM_SOCKET,
   MONGOC_ERROR_STREAM_CONNECT,
   MONGOC_ERROR_STREAM_NOT_ESTABLISHED,

   MONGOC_ERROR_CLIENT_NOT_READY,
   MONGOC_ERROR_CLIENT_TOO_BIG,
   MONGOC_ERROR_CLIENT_TOO_SMALL,
   MONGOC_ERROR_CLIENT_GETNONCE,
   MONGOC_ERROR_CLIENT_AUTHENTICATE,
   MONGOC_ERROR_CLIENT_NO_ACCEPTABLE_PEER,
   MONGOC_ERROR_CLIENT_IN_EXHAUST,

   MONGOC_ERROR_PROTOCOL_INVALID_REPLY,
   MONGOC_ERROR_PROTOCOL_BAD_WIRE_VERSION,

   MONGOC_ERROR_CURSOR_INVALID_CURSOR,

   MONGOC_ERROR_QUERY_FAILURE,

   MONGOC_ERROR_BSON_INVALID,

   MONGOC_ERROR_MATCHER_INVALID,

   MONGOC_ERROR_NAMESPACE_INVALID,
   MONGOC_ERROR_NAMESPACE_INVALID_FILTER_TYPE,

   MONGOC_ERROR_COMMAND_INVALID_ARG,

   MONGOC_ERROR_COLLECTION_INSERT_FAILED,
   MONGOC_ERROR_COLLECTION_UPDATE_FAILED,
   MONGOC_ERROR_COLLECTION_DELETE_FAILED,
   MONGOC_ERROR_COLLECTION_DOES_NOT_EXIST = 26,

   MONGOC_ERROR_GRIDFS_INVALID_FILENAME,

   MONGOC_ERROR_SCRAM_NOT_DONE,
   MONGOC_ERROR_SCRAM_PROTOCOL_ERROR,

   MONGOC_ERROR_QUERY_COMMAND_NOT_FOUND = 59,
   MONGOC_ERROR_QUERY_NOT_TAILABLE = 13051,

   MONGOC_ERROR_SERVER_SELECTION_BAD_WIRE_VERSION,
   MONGOC_ERROR_SERVER_SELECTION_FAILURE,
   MONGOC_ERROR_SERVER_SELECTION_INVALID_ID,

   MONGOC_ERROR_GRIDFS_CHUNK_MISSING,
   MONGOC_ERROR_GRIDFS_PROTOCOL_ERROR,

   /* Dup with query failure. */
   MONGOC_ERROR_PROTOCOL_ERROR = 17,

   MONGOC_ERROR_WRITE_CONCERN_ERROR = 64,

   MONGOC_ERROR_DUPLICATE_KEY = 11000,

   MONGOC_ERROR_MAX_TIME_MS_EXPIRED = 50,

   MONGOC_ERROR_CHANGE_STREAM_NO_RESUME_TOKEN,
   MONGOC_ERROR_CLIENT_SESSION_FAILURE,
   MONGOC_ERROR_TRANSACTION_INVALID_STATE,
   MONGOC_ERROR_GRIDFS_CORRUPT,
   MONGOC_ERROR_GRIDFS_BUCKET_FILE_NOT_FOUND,
   MONGOC_ERROR_GRIDFS_BUCKET_STREAM,

   /* An error related to initializing client side encryption. */
   MONGOC_ERROR_CLIENT_INVALID_ENCRYPTION_STATE,

   MONGOC_ERROR_CLIENT_INVALID_ENCRYPTION_ARG,


   /* An error related to server version api */
   MONGOC_ERROR_CLIENT_API_ALREADY_SET,
   MONGOC_ERROR_CLIENT_API_FROM_POOL,
   MONGOC_ERROR_POOL_API_ALREADY_SET,
   MONGOC_ERROR_POOL_API_TOO_LATE,

   MONGOC_ERROR_CLIENT_INVALID_LOAD_BALANCER,

   // Azure errors
   MONGOC_ERROR_AZURE_HTTP,
   MONGOC_ERROR_AZURE_BAD_JSON,
} mongoc_error_code_t;

MONGOC_EXPORT (bool)
mongoc_error_has_label (const bson_t *reply, const char *label);

BSON_END_DECLS


#endif /* MONGOC_ERRORS_H */
