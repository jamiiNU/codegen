// All of the Node.js APIs are available in the preload process.
// It has the same sandbox as a Chrome extension.
const { contextBridge, ipcRenderer } = require("electron");
const child_process = require('node:child_process');
const fs = require('fs-extra');
// const rimraf =  require ( 'rimraf' );

// As an example, here we use the exposeInMainWorld API to expose the browsers
// and node versions to the main window.
// They'll be accessible at "window.versions".
process.once("loaded", () => {
  contextBridge.exposeInMainWorld("versions", process.versions);
  // [Workaround] app.asar.unpacked
  contextBridge.exposeInMainWorld("__dirname", __dirname.replace("\\app.asar\\", "\\app.asar.unpacked\\"));
  contextBridge.exposeInMainWorld("child_process", child_process);
  contextBridge.exposeInMainWorld("fs", fs);
  // contextBridge.exposeInMainWorld("rimraf", rimraf);
  contextBridge.exposeInMainWorld("electronAPI", {
    window_open: (href) => ipcRenderer.send('window_open', href),

    child_process_spawn: (common, args, options) => ipcRenderer.send('child_process_spawn', common, args, options),
    child_process_spawn_io: (type, msg) => ipcRenderer.on('child_process_spawn_io', type, msg),
  });
});