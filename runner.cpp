#include <aws/lambda-runtime/runtime.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <iostream>

using namespace std;
using namespace aws::lambda_runtime;
using namespace Aws::Utils::Json;

/*
invocation_response my_handler(invocation_request const& req) {
    // Parse the input
    JsonValue json(req.payload);
    if (!json.WasParseSuccessful()) {
        return invocation_response::failure("Invalid JSON", "InvalidJSON");
    }

    auto view = json.View();

    JsonValue response;
    cout << "Ran deleteAll successfully.";
    
    return invocation_response::success(response.View().WriteCompact(), "application/json");
}
*/

int main() {
              //run_handler(my_handler);
                JsonValue response; 
                return 0;
}
