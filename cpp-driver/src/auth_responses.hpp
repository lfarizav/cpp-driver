/*
  Copyright (c) 2014-2017 DataStax

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef __CASS_AUTH_RESPONSES_HPP_INCLUDED__
#define __CASS_AUTH_RESPONSES_HPP_INCLUDED__

#include "constants.hpp"
#include "response.hpp"
#include "string_ref.hpp"

#include <string>

namespace cass {

class AuthenticateResponse : public Response {
public:
  AuthenticateResponse()
    : Response(CQL_OPCODE_AUTHENTICATE) { }

  const std::string& class_name() const { return class_name_; }

  bool decode(int version, char* buffer, size_t size);

private:
  std::string class_name_;
};

class AuthChallengeResponse : public Response {
public:
  AuthChallengeResponse()
    : Response(CQL_OPCODE_AUTH_CHALLENGE) { }

  const std::string& token() const { return token_; }

  bool decode(int version, char* buffer, size_t size);

private:
  std::string token_;
};

class AuthSuccessResponse : public Response {
public:
  AuthSuccessResponse()
    : Response(CQL_OPCODE_AUTH_SUCCESS) { }

  const std::string& token() const { return token_; }

  bool decode(int version, char* buffer, size_t size);

private:
  std::string token_;
};

} // namespace cass

#endif
