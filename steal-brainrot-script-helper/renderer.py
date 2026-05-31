def render_script(script: str) -> str:
    """Simple syntax highlight using ANSI codes (just keywords)."""
    keywords = ["function", "end", "if", "then", "else", "for", "while", "do", "local", "return"]
    lines = script.split("\n")
    highlighted = []
    for line in lines:
        for kw in keywords:
            line = line.replace(kw, f"\033[1;34m{kw}\033[0m")
        highlighted.append(line)
    return "\n".join(highlighted)