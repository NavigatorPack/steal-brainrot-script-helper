import requests
import re

def scrape_script(url: str) -> str:
    """Scrape raw Lua script from a Roblox paste or raw URL."""
    if "pastebin.com" in url:
        if not url.endswith("/raw"):
            url = url.rstrip("/") + "/raw"
    elif "roblox.com" in url:
        # Simulate extraction from a library page
        raise NotImplementedError("Roblox library scraping not implemented yet.")
    
    response = requests.get(url, timeout=10)
    response.raise_for_status()
    content = response.text

    # If wrapped in <pre> tags (pastebin raw sometimes), extract
    match = re.search(r"<pre[^>]*>(.*?)</pre>", content, re.DOTALL | re.IGNORECASE)
    if match:
        content = match.group(1)
    
    return content