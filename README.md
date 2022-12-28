# DEEP-Laby

## Project Description
explain the project

## Authenticate before pushing
- Generate new access token via Github -> Settings/Developer settings/Personal access tokens/Tokens (classic)
- Copy the token
- In CLI:

```bash
$ git remote -v
```

```bash
$ git remote set-url origin https://<github_username>:<access_token>@github/<github_username>/<repo_name>.git
```

- Push the project:

```bash
$ git push origin master
```
