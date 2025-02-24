<?php
$words = ["eat", "tea", "tan", "ate", "nat", "bat"];
//$words = [""];

function getSubarrayWithoutIndex(array $words, int $indexToRemove): array {
    $result = [];
    foreach ($words as $index => $word) {
        if ($index === $indexToRemove) {
            continue;
        }
        $result[] = $word;
    }
    return $result;
}

function combineWordWithArray(string $word, array $characters): array {
    $result = [];

    if (empty($characters)) {
        //echo "word = $word" . PHP_EOL;
        $result[] = $word;
    }

    foreach ($characters as $index => $character) {
        $subarrayWithoutIndex = getSubarrayWithoutIndex($characters, $index);
        $result[] = implode('', combineWordWithArray($word . $character, $subarrayWithoutIndex));
    }

    return $result;
}

function processCharacters(array $characters): array {
    $result = [];
    foreach ($characters as $index => $character) {
        $subarrayWithoutIndex = getSubarrayWithoutIndex($characters, $index);
        //echo print_r($subarrayWithoutIndex, true) . PHP_EOL;

        $subResult = combineWordWithArray($character, $subarrayWithoutIndex);
        //echo 'subResult = ' . print_r($subResult, true) . PHP_EOL;

        foreach ($subResult as $currentSubResult) {
            $result[] = $currentSubResult;
        }
    }
    return $result;
}

$processedWords = [];
$result = [];

function getGroupedAnagrams(array $words, array $allAnagramsForWord): array {
    $groupedAnagrams = [];
    foreach ($words as $word) {
        if (in_array($word, $allAnagramsForWord)) {
            $groupedAnagrams[] = $word;
        }
    }
    return $groupedAnagrams;
}

foreach ($words as $word) {
    if (in_array($word, $processedWords)) {
        continue;
    }

    echo 'Running process for word ' . $word . PHP_EOL;

    $wordCharacters = str_split($word);
    //echo print_r($wordCharacters, true) . PHP_EOL;
    echo "wordCharacters = " . implode(', ', $wordCharacters) . PHP_EOL;

    $anagrams = processCharacters($wordCharacters);
    echo 'anagrams = ' . print_r($anagrams, true) . PHP_EOL;

    $groupedAnagrams = getGroupedAnagrams($words, $anagrams);
    echo 'groupedAnagrams = ' . print_r($groupedAnagrams, true) . PHP_EOL;

    foreach ($groupedAnagrams as $anagram) {
        $processedWords[] = $anagram;
    }
    echo 'processedWords = ' . print_r($processedWords, true) . PHP_EOL;

    $result[] = $groupedAnagrams;

    echo PHP_EOL;
}

echo print_r($result, true);
