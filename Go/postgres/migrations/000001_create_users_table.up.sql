CREATE EXTENSION IF NOT EXISTS "uuid-ossp";

CREATE TABLE users (
    id uuid DEFAULT uuid_generate_v4() not null primary key,
    name varchar not null unique,
    email varchar not null,
    age int not null
)