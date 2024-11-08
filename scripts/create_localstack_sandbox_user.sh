#!/bin/bash

# automate steps in https://github.com/tiurin/localstack/blob/655ca21c1f067e17beadcad5e3bafb4f5b36850d/docs/testing/integration-tests/README.md#creating-an-aws-sandbox-account

aws iam create-user --user-name localstack-testing
admin_access_policy_arn=$(aws iam list-policies --query 'Policies[?PolicyName==`AdministratorAccess`].{ARN:Arn}' --output text)
aws iam attach-user-policy --user-name localstack-testing --policy-arn $admin_access_policy_arn
aws iam create-access-key --user-name localstack-testing
