import sys
import argparse
from scraper import scrape_script
from analyzer import analyze_script
from renderer import render_script

def main():
    parser = argparse.ArgumentParser(description="Steal a Brainrot Roblox Script")
    parser.add_argument("url", help="URL of the Roblox script to steal")
    parser.add_argument("--output", "-o", default="stolen_script.lua", help="Output file name")
    parser.add_argument("--analyze", "-a", action="store_true", help="Analyze script after stealing")
    args = parser.parse_args()

    print(f"[*] Stealing script from {args.url}...")
    raw_script = scrape_script(args.url)

    print(f"[*] Saving to {args.output}")
    with open(args.output, "w", encoding="utf-8") as f:
        f.write(raw_script)

    if args.analyze:
        print("[*] Analyzing script...")
        analysis = analyze_script(raw_script)
        print(f"    Lines: {analysis['lines']}")
        print(f"    Functions: {analysis['functions']}")
        print(f"    Has obfuscation: {analysis['has_obfuscation']}")

    print("[+] Done! Script stolen successfully.")

if __name__ == "__main__":
    main()