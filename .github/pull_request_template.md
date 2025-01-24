# Description of Changes

**What does this PR do?**  
Provide a clear and concise description of the changes introduced by this PR.  
Example: "This PR adds pagination support to the repository listing API."

**Problem solved or feature added**  
- Fixes #123 (if applicable).  
- Adds a new feature for [describe the feature].

---

## Details of Changes

- **Additions** :  
  - Added pagination with `page` and `per_page` parameters.  
  - Added unit tests for pagination.  

- **Modifications** :  
  - Updated documentation to include pagination.  

- **Deletions** :  
  - Removed unnecessary or obsolete code.  

---

## How to Test These Changes?

1. Use the following command to test pagination:  
   ```bash
   curl -H "Authorization: Bearer YOUR_TOKEN" "http://localhost:8080/repos?page=2&per_page=10"
   ```  
2. Run the unit tests:  
   ```bash
   make test
   ```  

---

## Pre-Submission Checklist

Before submitting this PR, ensure you have completed the following tasks:  

- [ ] I have added a clear description of the changes.  
- [ ] I have referenced relevant issues (e.g., "Fixes #123").  
- [ ] I have added or updated unit tests.  
- [ ] I have updated documentation (README, comments, etc.).  
- [ ] I have ensured the code follows the project's guidelines.  
- [ ] I have removed any debug code or unnecessary comments.  

---

## Screenshots or Demos (if applicable)

Add screenshots or GIFs to showcase visual changes:  
![Pagination Example](https://example.com/pagination-screenshot.png)  

---

## Additional Information

Add any additional information that might help reviewers understand your PR.  

---

Thank you for your contribution! 🚀
```

---