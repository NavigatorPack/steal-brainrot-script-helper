import re

def analyze_script(script: str) -> dict:
    """Return basic analysis of a Lua script."""
    lines = script.strip().split("\n")
    func_count = len(re.findall(r"\bfunction\b", script))
    has_obfuscation = bool(re.search(r"loadstring|decode|base64|_G\[", script, re.IGNORECASE))
    return {
        "lines": len(lines),
        "functions": func_count,
        "has_obfuscation": has_obfuscation,
    }