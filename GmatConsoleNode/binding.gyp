{
  'targets': [
    {
      'target_name': 'GmatConsoleNode',
      'sources': [ 'GmatConsoleNode.cpp' ],
      'libraries': [ '-lGmatBase', '-lGmatConsole' ],
      'link_settings': {'libraries': [ '-L./' ] }
    }
  ]
}