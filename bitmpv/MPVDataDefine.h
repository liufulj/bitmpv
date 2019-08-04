#ifndef MPV_DATA_DEFINE_H_
#define MPV_DATA_DEFINE_H_
#include<string>

//command
struct MPVCommand  {

	std::string cmd;
	MPVCommand() {

	}
	MPVCommand(std::string value) {
		cmd = value;
	}

	/** ignore */
	static MPVCommand ignore;
	/** seek <seconds> [relative|absolute|absolute-percent|relative-percent|exact|keyframes] */
	static MPVCommand seek;
	/** revert-seek [mode] */
	static MPVCommand revertSeek;
	/** frame-step */
	static MPVCommand frameStep;
	/** frame-back-step */
	static MPVCommand frameBackStep;
	/** set <property> "<value>" */
	static MPVCommand set;
	/** add <property> [<value>] */
	static MPVCommand add;
	/** cycle <property> [up|down] */
	static MPVCommand cycle;
	/** multiply <property> <factor> */
	static MPVCommand multiply;
	/** screenshot [subtitles|video|window|single|each-frame] */
	static MPVCommand screenshot;
	/** screenshot-to-file "<filename>" [subtitles|video|window] */
	static MPVCommand screenshotToFile;
	/** playlist-next [weak|force] */
	static MPVCommand playlistNext;
	/** playlist-prev [weak|force] */
	static MPVCommand playlistPrev;
	/** loadfile "<file>" [replace|append|append-play [options]] */
	static MPVCommand loadfile;
	/** loadlist "<playlist>" [replace|append] */
	static MPVCommand loadlist;
	/** playlist-clear */
	static MPVCommand playlistClear;
	/** playlist-remove current|<index> */
	static MPVCommand playlistRemove;
	/** playlist-move <index1> <index2> */
	static MPVCommand playlistMove;
	/** playlist-shuffle */
	static MPVCommand playlistShuffle;
	/** run "command" "arg1" "arg2" ... */
	static MPVCommand run;
	/** quit [<code>] */
	static MPVCommand quit;
	/** quit-watch-later [<code>] */
	static MPVCommand quitWatchLater;
	/** sub-add "<file>" [<flags> [<title> [<lang>]]] */
	static MPVCommand subAdd;
	/** sub-remove [<id>] */
	static MPVCommand subRemove;
	/** sub-reload [<id>] */
	static MPVCommand subReload;
	/** sub-step <skip> */
	static MPVCommand subStep;
	/** sub-seek <skip> */
	static MPVCommand subSeek;
	/** print-text "<string>" */
	static MPVCommand printText;
	/** show-text "<string>" [<duration>|- [<level>]] */
	static MPVCommand showText;
	/** expand-text "<string>" */
	static MPVCommand expandText;
	/** show-progress */
	static MPVCommand showProgress;
	/** write-watch-later-config */
	static MPVCommand writeWatchLaterConfig;
	/** stop */
	static MPVCommand stop;
	/** mouse <x> <y> [<button> [single|double]] */
	static MPVCommand mouse;
	/** keypress <key_name> */
	static MPVCommand keypress;
	/** keydown <key_name> */
	static MPVCommand keydown;
	/** keyup [<key_name>] */
	static MPVCommand keyup;
	/** audio-add "<file>" [<flags> [<title> [<lang>]]] */
	static MPVCommand audioAdd;
	/** audio-remove [<id>] */
	static MPVCommand audioRemove;
	/** audio-reload [<id>] */
	static MPVCommand audioReload;
	/** rescan-external-files [<mode>] */
	static MPVCommand rescanExternalFiles;
	/** af set|add|toggle|del|clr "filter1=params,filter2,..." */
	static MPVCommand af;
	/** vf set|add|toggle|del|clr "filter1=params,filter2,..." */
	static MPVCommand vf;
	/** cycle-values ["!reverse"] <property> "<value1>" "<value2>" ... */
	static MPVCommand cycleValues;
	/** enable-section "<section>" [flags] */
	static MPVCommand enableSection;
	/** disable-section "<section>" */
	static MPVCommand disableSection;
	/** define-section "<section>" "<contents>" [default|force] */
	static MPVCommand defineSection;
	/** overlay-add <id> <x> <y> "<file>" <offset> "<fmt>" <w> <h> <stride> */
	static MPVCommand overlayAdd;
	/** overlay-remove <id> */
	static MPVCommand overlayRemove;
	/** script-message "<arg1>" "<arg2>" ... */
	static MPVCommand scriptMessage;
	/** script-message-to "<target>" "<arg1>" "<arg2>" ... */
	static MPVCommand scriptMessageTo;
	/** script-binding "<name>" */
	static MPVCommand scriptBinding;
	/** ab-loop */
	static MPVCommand abLoop;
	/** drop-buffers */
	static MPVCommand dropBuffers;
	/** screenshot-raw [subtitles|video|window] */
	static MPVCommand screenshotRaw;
	/** vf-command "<label>" "<cmd>" "<args>" */
	static MPVCommand vfCommand;
	/** af-command "<label>" "<cmd>" "<args>" */
	static MPVCommand afCommand;
	/** apply-profile "<name>" */
	static MPVCommand applyProfile;
	/** load-script "<path>" */
	static MPVCommand loadScript;


};


//option
namespace MPVOption {
	struct TrackSelection {
		/** --alang=<languagecode[ */
		static std::string alang;
		/** --slang=<languagecode[ */
		static std::string slang ;
		/** --vlang=<...> */
		static std::string vlang;
		/** --aid=<ID|auto|no> */
		static std::string aid;
		/** --sid=<ID|auto|no> */
		static std::string sid;
		/** --vid=<ID|auto|no> */
		static std::string vid;
		/** --ff-aid=<ID|auto|no> */
		static std::string ffAid;
		/** --ff-sid=<ID|auto|no> */
		static std::string ffSid;
		/** --ff-vid=<ID|auto|no> */
		static std::string ffVid;
		/** --edition=<ID|auto> */
		static std::string edition;
		/** --track-auto-selection=<yes|no> */
		static std::string trackAutoSelection;
	};
	
	struct PlaybackControl {
		/** --start=<relative time> */
		static std::string  start;
		/** --end=<time> */
		static std::string end;
		/** --length=<relative time> */
		static std::string length;
		/** --rebase-start-time=<yes|no> */
		static std::string rebaseStartTime;
		/** --speed=<0.01-100> */
		static std::string speed;
		/** --pause */
		static std::string pause ;
		/** --shuffle */
		static std::string shuffle;
		/** --chapter=<start[-end]> */
		static std::string chapter;
		/** --playlist-start=<auto|index> */
		static std::string playlistStart ;
		/** --playlist=<filename> */
		static std::string playlist;
		/** --chapter-merge-threshold=<number> */
		static std::string chapterMergeThreshold ;
		/** --chapter-seek-threshold=<seconds> */
		static std::string chapterSeekThreshold;
		/** --hr-seek=<no|absolute|yes> */
		static std::string hrSeek;
		/** --hr-seek-demuxer-offset=<seconds> */
		static std::string hrSeekDemuxerOffset;
		/** --hr-seek-framedrop=<yes|no> */
		static std::string hrSeekFramedrop;
		/** --index=<mode> */
		static std::string index;
		/** --load-unsafe-playlists */
		static std::string loadUnsafePlaylists;
		/** --access-references=<yes|no> */
		static std::string accessReferences;
		/** --loop-playlist=<N|inf|force|no> */
		static std::string loopPlaylist;
		/** --loop-file=<N|inf|no> */
		static std::string loopFile;
		/** --loop=<N|inf|no> */
		static std::string loop;
		/** --ab-loop-a=<time> */
		static std::string abLoopA;
		/** --ab-loop-b=<time> */
		static std::string abLoopB ;
		/** --ordered-chapters */
		static std::string orderedChapters;
		/** --no-ordered-chapters */
		static std::string noOrderedChapters ;
		/** --ordered-chapters-files=<playlist-file> */
		static std::string orderedChaptersFiles;
		/** --chapters-file=<filename> */
		static std::string chaptersFile;
		/** --sstep=<sec> */
		static std::string sstep;
		/** --stop-playback-on-init-failure=<yes|no> */
		static std::string stopPlaybackOnInitFailure;
	};

	struct ProgramBehavior {
		/** --help */
		static std::string help;
		/** --h */
		static std::string h;
		/** --version */
		static std::string version ;
		/** --no-config */
		static std::string noConfig ;
		/** --list-options */
		static std::string listOptions ;
		/** --list-properties */
		static std::string listProperties ;
		/** --list-protocols */
		static std::string listProtocols  ;
		/** --log-file=<path> */
		static std::string logFile ;
		/** --config-dir=<path> */
		static std::string configDir  ;
		/** --save-position-on-quit */
		static std::string savePositionOnQuit  ;
		/** --dump-stats=<filename> */
		static std::string dumpStats ;
		/** --idle=<no|yes|once> */
		static std::string idle  ;
		/** --include=<configuration-file> */
		static std::string include  ;
		/** --load-scripts=<yes|no> */
		static std::string loadScripts ;
		/** --script=<filename> */
		static std::string script  ;
		/** --script-opts=key1=value1 */
		static std::string scriptOpts ;
		/** --merge-files */
		static std::string mergeFiles ;
		/** --no-resume-playback */
		static std::string noResumePlayback ;
		/** --profile=<profile1 */
		static std::string profile ;
		/** --reset-on-next-file=<all|option1 */
		static std::string resetOnNextFile ;
		/** --write-filename-in-watch-later-config */
		static std::string writeFilenameInWatchLaterConfig  ;
		/** --ignore-path-in-watch-later-config */
		static std::string ignorePathInWatchLaterConfig ;
		/** --show-profile=<profile> */
		static std::string showProfile ;
		/** --use-filedir-conf */
		static std::string useFiledirConf ;
		/** --ytdl */
		static std::string ytdl ;
		/** --no-ytdl */
		static std::string noYtdl  ;
		/** --ytdl-format=<best|worst|mp4|webm|...> */
		static std::string ytdlFormat ;
		/** --ytdl-raw-options=<key>=<value>[ */
		static std::string ytdlRawOptions;
		/** --load-stats-overlay=<yes|no> */
		static std::string loadStatsOverlay ;
		/** --player-operation-mode=<cplayer|pseudo-gui> */
		static std::string playerOperationMode;
	};

	struct Video {
		/** --vo=<driver> */
		static std::string vo ;
		/** --vd=<...> */
		static std::string vd ;
		/** --vf=<filter1[=parameter1:parameter2:...] */
		static std::string vf ;
		/** --untimed */
		static std::string untimed ;
		/** --framedrop=<mode> */
		static std::string framedrop  ;
		/** --display-fps=<fps> */
		static std::string displayFps ;
		/** --hwdec=<api> */
		static std::string hwdec ;
		/** --gpu-hwdec-interop=<auto|all|no|name> */
		static std::string gpuHwdecInterop  ;
		/** --hwdec-image-format=<name> */
		static std::string hwdecImageFormat ;
		/** --videotoolbox-format=<name> */
		static std::string videotoolboxFormat ;
		/** --panscan=<0.0-1.0> */
		static std::string panscan ;
		/** --video-aspect=<ratio|no> */
		static std::string videoAspect ;
		/** --video-aspect-method=<bitstream|container> */
		static std::string videoAspectMethod  ;
		/** --video-unscaled=<no|yes|downscale-big> */
		static std::string videoUnscaled ;
		/** --video-pan-x=<value> */
		static std::string videoPanX ;
		/** --video-pan-y=<value> */
		static std::string videoPanY  ;
		/** --video-rotate=<0-359|no> */
		static std::string videoRotate  ;
		/** --video-stereo-mode=<no|mode> */
		static std::string videoStereoMode  ;
		/** --video-zoom=<value> */
		static std::string videoZoom  ;
		/** --video-align-x=<-1-1> */
		static std::string videoAlignX ;
		/** --video-align-y=<-1-1> */
		static std::string videoAlignY ;
		/** --correct-pts */
		static std::string correctPts ;
		/** --no-correct-pts */
		static std::string noCorrectPts ;
		/** --fps=<float> */
		static std::string fps ;
		/** --deinterlace=<yes|no> */
		static std::string deinterlace;
		/** --frames=<number> */
		static std::string frames ;
		/** --video-output-levels=<outputlevels> */
		static std::string videoOutputLevels;
		/** --hwdec-codecs=<codec1 */
		static std::string hwdecCodecs ;
		/** --vd-lavc-check-hw-profile=<yes|no> */
		static std::string vdLavcCheckHwProfile  ;
		/** --vd-lavc-software-fallback=<yes|no|N> */
		static std::string vdLavcSoftwareFallback ;
		/** --vd-lavc-dr=<yes|no> */
		static std::string vdLavcDr ;
		/** --vd-lavc-bitexact */
		static std::string vdLavcBitexact ;
		/** --vd-lavc-fast */
		static std::string vdLavcFast;
		/** --vd-lavc-o=<key>=<value>[ */
		static std::string vdLavcO ;
		/** --vd-lavc-show-all=<yes|no> */
		static std::string vdLavcShowAll ;
		/** --vd-lavc-skiploopfilter=<skipvalue> (H.264 only) */
		static std::string vdLavcSkiploopfilter ;
		/** --vd-lavc-skipidct=<skipvalue> (MPEG-1/2 only) */
		static std::string vdLavcSkipidct ;
		/** --vd-lavc-skipframe=<skipvalue> */
		static std::string vdLavcSkipframe  ;
		/** --vd-lavc-framedrop=<skipvalue> */
		static std::string vdLavcFramedrop ;
		/** --vd-lavc-threads=<N> */
		static std::string vdLavcThreads;
	};

	struct Audio {
		/** --audio-pitch-correction=<yes|no> */
		static std::string audioPitchCorrection;
		/** --audio-device=<name> */
		static std::string audioDevice;
		/** --audio-exclusive=<yes|no> */
		static std::string audioExclusive;
		/** --audio-fallback-to-null=<yes|no> */
		static std::string audioFallbackToNull;
		/** --ao=<driver> */
		static std::string ao;
		/** --af=<filter1[=parameter1:parameter2:...] */
		static std::string af;
		/** --audio-spdif=<codecs> */
		static std::string audioSpdif;
		/** --ad=<decoder1 */
		static std::string ad  ;
		/** --volume=<value> */
		static std::string volume;
		/** --replaygain=<no|track|album> */
		static std::string replaygain;
		/** --replaygain-preamp=<db> */
		static std::string replaygainPreamp;
		/** --replaygain-clip=<yes|no> */
		static std::string replaygainClip;
		/** --replaygain-fallback=<db> */
		static std::string replaygainFallback;
		/** --audio-delay=<sec> */
		static std::string audioDelay;
		/** --mute=<yes|no|auto> */
		static std::string mute;
		/** --softvol=<no|yes|auto> */
		static std::string softvol;
		/** --audio-demuxer=<[+]name> */
		static std::string audioDemuxer;
		/** --ad-lavc-ac3drc=<level> */
		static std::string adLavcAc3drc;
		/** --ad-lavc-downmix=<yes|no> */
		static std::string adLavcDownmix;
		/** --ad-lavc-threads=<0-16> */
		static std::string adLavcThreads;
		/** --ad-lavc-o=<key>=<value>[ */
		static std::string adLavcO;
		/** --ad-spdif-dtshd=<yes|no> */
		static std::string adSpdifDtshd;
		/** --dtshd */
		static std::string dtshd;
		/** --no-dtshd */
		static std::string noDtshd;
		/** --audio-channels=<auto-safe|auto|layouts> */
		static std::string audioChannels;
		/** --audio-normalize-downmix=<yes|no> */
		static std::string audioNormalizeDownmix;
		/** --audio-display=<no|attachment> */
		static std::string audioDisplay;
		/** --audio-files=<files> */
		static std::string audioFiles;
		/** --audio-file=<file> */
		static std::string audioFile;
		/** --audio-format=<format> */
		static std::string audioFormat;
		/** --audio-samplerate=<Hz> */
		static std::string audioSamplerate;
		/** --gapless-audio=<no|yes|weak> */
		static std::string gaplessAudio;
		/** --initial-audio-sync */
		static std::string initialAudioSync;
		/** --no-initial-audio-sync */
		static std::string noInitialAudioSync;
		/** --volume-max=<100.0-1000.0> */
		static std::string volumeMax;
		/** --softvol-max=<...> */
		static std::string softvolMax;
		/** --audio-file-auto=<no|exact|fuzzy|all> */
		static std::string audioFileAuto;
		/** --no-audio-file-auto */
		static std::string noAudioFileAuto;
		/** --audio-file-paths=<path1:path2:...> */
		static std::string audioFilePaths;
		/** --audio-client-name=<name> */
		static std::string audioClientName;
		/** --audio-buffer=<seconds> */
		static std::string audioBuffer;
		/** --audio-stream-silence=<yes|no> */
		static std::string audioStreamSilence;
		/** --audio-wait-open=<secs> */
		static std::string audioWaitOpen  ;
	};
	

	struct Subtitles {
		/** --sub-demuxer=<[+]name> */
		static std::string subDemuxer;
		/** --sub-delay=<sec> */
		static std::string subDelay;
		/** --sub-files=<file-list> */
		static std::string subFiles;
		/** --sub-file=<filename> */
		static std::string subFile;
		/** --secondary-sid=<ID|auto|no> */
		static std::string secondarySid;
		/** --sub-scale=<0-100> */
		static std::string subScale;
		/** --sub-scale-by-window=<yes|no> */
		static std::string subScaleByWindow;
		/** --sub-scale-with-window=<yes|no> */
		static std::string subScaleWithWindow;
		/** --sub-ass-scale-with-window=<yes|no> */
		static std::string subAssScaleWithWindow;
		/** --embeddedfonts */
		static std::string embeddedfonts;
		/** --no-embeddedfonts */
		static std::string noEmbeddedfonts;
		/** --sub-pos=<0-100> */
		static std::string subPos;
		/** --sub-speed=<0.1-10.0> */
		static std::string subSpeed;
		/** --sub-ass-force-style=<[Style.]Param=Value[ */
		static std::string subAssForceStyle;
		/** --sub-ass-hinting=<none|light|normal|native> */
		static std::string subAssHinting;
		/** --sub-ass-line-spacing=<value> */
		static std::string subAssLineSpacing;
		/** --sub-ass-shaper=<simple|complex> */
		static std::string subAssShaper;
		/** --sub-ass-styles=<filename> */
		static std::string subAssStyles;
		/** --sub-ass-override=<yes|no|force|scale|strip> */
		static std::string subAssOverride;
		/** --sub-ass-force-margins */
		static std::string subAssForceMargins;
		/** --sub-use-margins */
		static std::string subUseMargins;
		/** --sub-ass-vsfilter-aspect-compat=<yes|no> */
		static std::string subAssVsfilterAspectCompat;
		/** --sub-ass-vsfilter-blur-compat=<yes|no> */
		static std::string subAssVsfilterBlurCompat;
		/** --sub-ass-vsfilter-color-compat=<basic|full|force-601|no> */
		static std::string subAssVsfilterColorCompat;
		/** --stretch-dvd-subs=<yes|no> */
		static std::string stretchDvdSubs;
		/** --stretch-image-subs-to-screen=<yes|no> */
		static std::string stretchImageSubsToScreen;
		/** --image-subs-video-resolution=<yes|no> */
		static std::string imageSubsVideoResolution;
		/** --sub-ass */
		static std::string subAss;
		/** --no-sub-ass */
		static std::string noSubAss;
		/** --sub-auto=<no|exact|fuzzy|all> */
		static std::string subAuto;
		/** --no-sub-auto */
		static std::string noSubAuto;
		/** --sub-codepage=<codepage> */
		static std::string subCodepage;
		/** --sub-fix-timing=<yes|no> */
		static std::string subFixTiming;
		/** --sub-forced-only */
		static std::string subForcedOnly;
		/** --sub-fps=<rate> */
		static std::string subFps;
		/** --sub-gauss=<0.0-3.0> */
		static std::string subGauss;
		/** --sub-gray */
		static std::string subGray;
		/** --sub-paths=<path1:path2:...> */
		static std::string subPaths;
		/** --sub-file-paths=<path-list> */
		static std::string subFilePaths;
		/** --sub-visibility */
		static std::string subVisibility;
		/** --no-sub-visibility */
		static std::string noSubVisibility ;
		/** --sub-clear-on-seek */
		static std::string subClearOnSeek;
		/** --testd::stringext-page=<1-999> */
		static std::string teletextPage;
		/** --sub-font=<name> */
		static std::string subFont;
		/** --sub-font-size=<size> */
		static std::string subFontSize;
		/** --sub-back-color=<color> */
		static std::string subBackColor;
		/** --sub-blur=<0..20.0> */
		static std::string subBlur;
		/** --sub-bold=<yes|no> */
		static std::string subBold;
		/** --sub-italic=<yes|no> */
		static std::string subItalic;
		/** --sub-border-color=<color> */
		static std::string subBorderColor;
		/** --sub-border-size=<size> */
		static std::string subBorderSize;
		/** --sub-color=<color> */
		static std::string subColor;
		/** --sub-margin-x=<size> */
		static std::string subMarginX;
		/** --sub-margin-y=<size> */
		static std::string subMarginY;
		/** --sub-align-x=<left|center|right> */
		static std::string subAlignX;
		/** --sub-align-y=<top|center|bottom> */
		static std::string subAlignY;
		/** --sub-justify=<auto|left|center|right> */
		static std::string subJustify;
		/** --sub-ass-justify=<yes|no> */
		static std::string subAssJustify;
		/** --sub-shadow-color=<color> */
		static std::string subShadowColor;
		/** --sub-shadow-offset=<size> */
		static std::string subShadowOffset;
		/** --sub-spacing=<size> */
		static std::string subSpacing;
		/** --sub-filter-sdh=<yes|no> */
		static std::string subFilterSdh;
		/** --sub-filter-sdh-harder=<yes|no> */
		static std::string subFilterSdhHarder;
		/** --sub-create-cc-track=<yes|no> */
		static std::string subCreateCcTrack;
	};


	struct Window {
		/** --title=<string> */
		static std::string title;
		/** --screen=<default|0-32> */
		static std::string screen;
		/** --fullscreen */
		static std::string fullscreen;
		/** --fs */
		static std::string fs;
		/** --fs-screen=<all|current|0-32> */
		static std::string fsScreen;
		/** --keep-open=<yes|no|always> */
		static std::string keepOpen;
		/** --keep-open-pause=<yes|no> */
		static std::string keepOpenPause;
		/** --image-display-duration=<seconds|inf> */
		static std::string imageDisplayDuration;
		/** --force-window=<yes|no|immediate> */
		static std::string forceWindow;
		/** --taskbar-progress */
		static std::string taskbarProgress;
		/** --no-taskbar-progress */
		static std::string noTaskbarProgress;
		/** --snap-window */
		static std::string snapWindow;
		/** --ontop */
		static std::string ontop;
		/** --ontop-level=<window|system|level> */
		static std::string ontopLevel;
		/** --border */
		static std::string border;
		/** --no-border */
		static std::string noBorder;
		/** --fit-border */
		static std::string fitBorder;
		/** --no-fit-border */
		static std::string noFitBorder;
		/** --on-all-workspaces */
		static std::string onAllWorkspaces;
		/** --geometry=<[W[xH]][+-x+-y]> */
		static std::string geometry;
		/** --autofit=<[W[xH]]> */
		static std::string autofit;
		/** --autofit-larger=<[W[xH]]> */
		static std::string autofitLarger;
		/** --autofit-smaller=<[W[xH]]> */
		static std::string autofitSmaller;
		/** --window-scale=<factor> */
		static std::string windowScale;
		/** --cursor-autohide=<number|no|always> */
		static std::string cursorAutohide;
		/** --cursor-autohide-fs-only */
		static std::string cursorAutohideFsOnly;
		/** --no-fixed-vo */
		static std::string noFixedVo;
		/** --fixed-vo */
		static std::string fixedVo;
		/** --force-rgba-osd-rendering */
		static std::string forceRgbaOsdRendering;
		/** --force-window-position */
		static std::string forceWindowPosition;
		/** --no-keepaspect */
		static std::string noKeepaspect;
		/** --keepaspect */
		static std::string keepaspect;
		/** --no-keepaspect-window */
		static std::string noKeepaspectWindow;
		/** --keepaspect-window */
		static std::string keepaspectWindow;
		/** --monitoraspect=<ratio> */
		static std::string monitoraspect;
		/** --hidpi-window-scale */
		static std::string hidpiWindowScale;
		/** --no-hidpi-window-scale */
		static std::string noHidpiWindowScale;
		/** --native-fs */
		static std::string nativeFs;
		/** --no-native-fs */
		static std::string noNativeFs;
		/** --monitorpixelaspect=<ratio> */
		static std::string monitorpixelaspect;
		/** --stop-screensaver */
		static std::string stopScreensaver;
		/** --no-stop-screensaver */
		static std::string noStopScreensaver;
		/** --wid=<ID> */
		static std::string wid;
		/** --no-window-dragging */
		static std::string noWindowDragging;
		/** --x11-name */
		static std::string x11Name;
		/** --x11-netwm=<yes|no|auto> */
		static std::string x11Netwm;
		/** --x11-bypass-compositor=<yes|no|fs-only|never> */
		static std::string x11BypassCompositor;
	};

	struct DiscDevices {
		/** --cdrom-device=<path> */
		static std::string cdromDevice;
		/** --dvd-device=<path> */
		static std::string dvdDevice;
		/** --bluray-device=<path> */
		static std::string blurayDevice;
		/** --cdda-speed=<value> */
		static std::string cddaSpeed;
		/** --cdda-paranoia=<0-2> */
		static std::string cddaParanoia;
		/** --cdda-sector-size=<value> */
		static std::string cddaSectorSize;
		/** --cdda-overlap=<value> */
		static std::string cddaOverlap;
		/** --cdda-toc-bias */
		static std::string cddaTocBias;
		/** --cdda-toc-offset=<value> */
		static std::string cddaTocOffset;
		/** --cdda-skip=<yes|no> */
		static std::string cddaSkip;
		/** --cdda-cdtext=<yes|no> */
		static std::string cddaCdtext;
		/** --dvd-speed=<speed> */
		static std::string dvdSpeed;
		/** --dvd-angle=<ID> */
		static std::string dvdAngle;
	};

	struct Equalizer {
		/** --brightness=<-100-100> */
		static std::string brightness;
		/** --contrast=<-100-100> */
		static std::string contrast ;
		/** --saturation=<-100-100> */
		static std::string saturation  ;
		/** --gamma=<-100-100> */
		static std::string gamma ;
		/** --hue=<-100-100> */
		static std::string hue;
	};

	struct Demuxer {
		/** --demuxer=<[+]name> */
		static std::string demuxer;
		/** --demuxer-lavf-analyzeduration=<value> */
		static std::string demuxerLavfAnalyzeduration;
		/** --demuxer-lavf-probe-info=<yes|no|auto> */
		static std::string demuxerLavfProbeInfo;
		/** --demuxer-lavf-probescore=<1-100> */
		static std::string demuxerLavfProbescore;
		/** --demuxer-lavf-allow-mimetype=<yes|no> */
		static std::string demuxerLavfAllowMimetype;
		/** --demuxer-lavf-format=<name> */
		static std::string demuxerLavfFormat;
		/** --demuxer-lavf-hacks=<yes|no> */
		static std::string demuxerLavfHacks;;
		/** --demuxer-lavf-genpts-mode=<no|lavf> */
		static std::string demuxerLavfGenptsMode;
		/** --demuxer-lavf-o=<key>=<value>[ */
		static std::string demuxerLavfO;
		/** --demuxer-lavf-probesize=<value> */
		static std::string demuxerLavfProbesize;
		/** --demuxer-lavf-buffersize=<value> */
		static std::string demuxerLavfBuffersize;
		/** --demuxer-mkv-subtitle-preroll=<yes|index|no> */
		static std::string demuxerMkvSubtitlePreroll;
		/** --mkv-subtitle-preroll */
		static std::string mkvSubtitlePreroll;
		/** --demuxer-mkv-subtitle-preroll-secs=<value> */
		static std::string demuxerMkvSubtitlePrerollSecs;
		/** --demuxer-mkv-subtitle-preroll-secs-index=<value> */
		static std::string demuxerMkvSubtitlePrerollSecsIndex;
		/** --demuxer-mkv-probe-video-duration=<yes|no|full> */
		static std::string demuxerMkvProbeVideoDuration;
		/** --demuxer-rawaudio-channels=<value> */
		static std::string demuxerRawaudioChannels;
		/** --demuxer-rawaudio-format=<value> */
		static std::string demuxerRawaudioFormat;
		/** --demuxer-rawaudio-rate=<value> */
		static std::string demuxerRawaudioRate;
		/** --demuxer-rawvideo-fps=<value> */
		static std::string demuxerRawvideoFps;
		/** --demuxer-rawvideo-w=<value> */
		static std::string demuxerRawvideoW;
		/** --demuxer-rawvideo-h=<value> */
		static std::string demuxerRawvideoH;
		/** --demuxer-rawvideo-format=<value> */
		static std::string demuxerRawvideoFormat;
		/** --demuxer-rawvideo-mp-format=<value> */
		static std::string demuxerRawvideoMpFormat;
		/** --demuxer-rawvideo-codec=<value> */
		static std::string demuxerRawvideoCodec;
		/** --demuxer-rawvideo-size=<value> */
		static std::string demuxerRawvideoSize;
		/** --demuxer-max-bytes=<bytes> */
		static std::string demuxerMaxBytes;
		/** --demuxer-max-back-bytes=<value> */
		static std::string demuxerMaxBackBytes;
		/** --demuxer-seekable-cache=<yes|no|auto> */
		static std::string demuxerSeekableCache;
		/** --demuxer-thread=<yes|no> */
		static std::string demuxerThread;
		/** --demuxer-readahead-secs=<seconds> */
		static std::string demuxerReadaheadSecs;
		/** --prefetch-playlist=<yes|no> */
		static std::string prefetchPlaylist;
		/** --force-seekable=<yes|no> */
		static std::string forceSeekable;
	};

	struct Input {
		/** --native-keyrepeat */
		static std::string nativeKeyrepeat;
		/** --input-ar-delay */
		static std::string inputArDelay;
		/** --input-ar-rate */
		static std::string inputArRate;
		/** --input-conf=<filename> */
		static std::string inputConf;
		/** --no-input-default-bindings */
		static std::string noInputDefaultBindings;
		/** --input-cmdlist */
		static std::string inputCmdlist;
		/** --input-doubleclick-time=<milliseconds> */
		static std::string inputDoubleclickTime;
		/** --input-keylist */
		static std::string inputKeylist;
		/** --input-key-fifo-size=<2-65000> */
		static std::string inputKeyFifoSize;
		/** --input-test */
		static std::string inputTest;
		/** --input-file=<filename> */
		static std::string inputFile;
		/** --input-terminal */
		static std::string inputTerminal;
		/** --no-input-terminal */
		static std::string noInputTerminal;
		/** --input-ipc-server=<filename> */
		static std::string inputIpcServer;
		/** --input-appleremote=<yes|no> */
		static std::string inputAppleremote;
		/** --input-cursor */
		static std::string inputCursor;
		/** --no-input-cursor */
		static std::string noInputCursor;
		/** --input-media-keys=<yes|no> */
		static std::string inputMediaKeys;
		/** --input-right-alt-gr */
		static std::string inputRightAltGr;
		/** --no-input-right-alt-gr */
		static std::string noInputRightAltGr;
		/** --input-vo-keyboard=<yes|no> */
		static std::string inputVoKeyboard;
	};

	struct OSD {
		/** --osc */
		static std::string osc;
		/** --no-osc */
		static std::string noOsc;
		/** --no-osd-bar */
		static std::string noOsdBar;
		/** --osd-bar */
		static std::string osdBar;
		/** --osd-duration=<time> */
		static std::string osdDuration;
		/** --osd-font=<name> */
		static std::string osdFont;
		/** --osd-font-size=<size> */
		static std::string osdFontSize;
		/** --osd-msg1=<string> */
		static std::string osdMsg1;
		/** --osd-msg2=<string> */
		static std::string osdMsg2;
		/** --osd-msg3=<string> */
		static std::string osdMsg3;
		/** --osd-status-msg=<string> */
		static std::string osdStatusMsg;
		/** --osd-playing-msg=<string> */
		static std::string osdPlayingMsg;
		/** --osd-bar-align-x=<-1-1> */
		static std::string osdBarAlignX;
		/** --osd-bar-align-y=<-1-1> */
		static std::string osdBarAlignY;
		/** --osd-bar-w=<1-100> */
		static std::string osdBarW;
		/** --osd-bar-h=<0.1-50> */
		static std::string osdBarH;
		/** --osd-back-color=<color> */
		static std::string osdBackColor;
		/** --osd-blur=<0..20.0> */
		static std::string osdBlur;
		/** --osd-bold=<yes|no> */
		static std::string osdBold;
		/** --osd-italic=<yes|no> */
		static std::string osdItalic;
		/** --osd-border-color=<color> */
		static std::string osdBorderColor;
		/** --osd-border-size=<size> */
		static std::string osdBorderSize;
		/** --osd-color=<color> */
		static std::string osdColor;
		/** --osd-fractions */
		static std::string osdFractions;
		/** --osd-level=<0-3> */
		static std::string osdLevel;
		/** --osd-margin-x=<size> */
		static std::string osdMarginX;
		/** --osd-margin-y=<size> */
		static std::string osdMarginY;
		/** --osd-align-x=<left|center|right> */
		static std::string osdAlignX;
		/** --osd-align-y=<top|center|bottom> */
		static std::string osdAlignY;
		/** --osd-scale=<factor> */
		static std::string osdScale;
		/** --osd-scale-by-window=<yes|no> */
		static std::string osdScaleByWindow;
		/** --osd-shadow-color=<color> */
		static std::string osdShadowColor;
		/** --osd-shadow-offset=<size> */
		static std::string osdShadowOffset;
		/** --osd-spacing=<size> */
		static std::string osdSpacing;
		/** --video-osd=<yes|no> */
		static std::string videoOsd;
	};

	struct Screenshot {
		/** --screenshot-format=<type> */
		static std::string screenshotFormat ;
		/** --screenshot-tag-colorspace=<yes|no> */
		static std::string screenshotTagColorspace ;
		/** --screenshot-high-bit-depth=<yes|no> */
		static std::string screenshotHighBitDepth ;
		/** --screenshot-template=<template> */
		static std::string screenshotTemplate ;
		/** --screenshot-directory=<path> */
		static std::string screenshotDirectory ;
		/** --screenshot-jpeg-quality=<0-100> */
		static std::string screenshotJpegQuality;
		/** --screenshot-jpeg-source-chroma=<yes|no> */
		static std::string screenshotJpegSourceChroma ;
		/** --screenshot-png-compression=<0-9> */
		static std::string screenshotPngCompression;
		/** --screenshot-png-filter=<0-5> */
		static std::string screenshotPngFilter;
	};

	struct SoftwareScaler {
		/** --sws-scaler=<name> */
		static std::string swsScaler;
		/** --sws-lgb=<0-100> */
		static std::string swsLgb;
		/** --sws-cgb=<0-100> */
		static std::string swsCgb;
		/** --sws-ls=<-100-100> */
		static std::string swsLs;
		/** --sws-cs=<-100-100> */
		static std::string swsCs;
		/** --sws-chs=<h> */
		static std::string swsChs;
		/** --sws-cvs=<v> */
		static std::string swsCvs;
	};
	
	struct Terminal {
		/** --quiet */
		static std::string quiet;
		/** --really-quiet */
		static std::string reallyQuiet;
		/** --no-terminal */
		static std::string noTerminal;
		/** --terminal */
		static std::string terminal;
		/** --no-msg-color */
		static std::string noMsgColor;
		/** --msg-level=<module1=level1 */
		static std::string msgLevel;
		/** --term-osd=<auto|no|force> */
		static std::string termOsd;
		/** --term-osd-bar */
		static std::string termOsdBar;
		/** --no-term-osd-bar */
		static std::string noTermOsdBar;
		/** --term-osd-bar-chars=<string> */
		static std::string termOsdBarChars;
		/** --term-playing-msg=<string> */
		static std::string termPlayingMsg;
		/** --term-status-msg=<string> */
		static std::string termStatusMsg;
		/** --msg-module */
		static std::string msgModule;
		/** --msg-time */
		static std::string msgTime;
	};

	struct Cache {
		/** --cache=<kBytes|yes|no|auto> */
		static std::string cache;
		/** --cache-default=<kBytes|no> */
		static std::string cacheDefault;
		/** --cache-initial=<kBytes> */
		static std::string cacheInitial;
		/** --cache-seek-min=<kBytes> */
		static std::string cacheSeekMin;
		/** --cache-backbuffer=<kBytes> */
		static std::string cacheBackbuffer;
		/** --cache-file=<TMP|path> */
		static std::string cacheFile;
		/** --cache-file-size=<kBytes> */
		static std::string cacheFileSize;
		/** --no-cache */
		static std::string noCache;
		/** --cache-secs=<seconds> */
		static std::string cacheSecs;
		/** --cache-pause */
		static std::string cachePause;
		/** --no-cache-pause */
		static std::string noCachePause;
	};

	struct Network {
		/** --user-agent=<string> */
		static std::string userAgent;
		/** --cookies */
		static std::string cookies;
		/** --no-cookies */
		static std::string noCookies;
		/** --cookies-file=<filename> */
		static std::string cookiesFile;
		/** --http-header-fields=<field1 */;
		static std::string httpHeaderFields;
		/** --tls-ca-file=<filename> */
		static std::string tlsCaFile;
		/** --tls-verify */
		static std::string tlsVerify;
		/** --tls-cert-file */
		static std::string tlsCertFile;
		/** --tls-key-file */
		static std::string tlsKeyFile;
		/** --referrer=<string> */
		static std::string referrer;
		/** --network-timeout=<seconds> */
		static std::string networkTimeout;
		/** --rtsp-transport=<lavf|udp|tcp|http> */
		static std::string rtspTransport;
		/** --hls-bitrate=<no|min|max|<rate>> */
		static std::string hlsBitrate;
	};

	struct DVB {
		/** --dvbin-card=<1-4> */
		static std::string dvbinCard;
		/** --dvbin-file=<filename> */
		static std::string dvbinFile;
		/** --dvbin-timeout=<1-30> */
		static std::string dvbinTimeout;
		/** --dvbin-full-transponder=<yes|no> */
		static std::string dvbinFullTransponder;
	};

	struct ALSAAudioOutputOptions {
		/** --alsa-device=<device> */
		static std::string alsaDevice;
		/** --alsa-resample=yes */
		static std::string alsaResample;
		/** --alsa-mixer-device=<device> */
		static std::string alsaMixerDevice;
		/** --alsa-mixer-name=<name> */
		static std::string alsaMixerName;
		/** --alsa-mixer-index=<number> */
		static std::string alsaMixerIndex;
		/** --alsa-non-interleaved */
		static std::string alsaNonInterleaved;
		/** --alsa-ignore-chmap */
		static std::string alsaIgnoreChmap;
	};
	
	struct GPURendererOptions {
		/** --scale=<filter> */
		static std::string scale;
		/** --cscale=<filter> */
		static std::string cscale;
		/** --dscale=<filter> */
		static std::string dscale;
		/** --tscale=<filter> */
		static std::string tscale;
		/** --scale-param1=<value> */
		static std::string scaleParam1;
		/** --scale-param2=<value> */
		static std::string scaleParam2;
		/** --cscale-param1=<value> */
		static std::string cscaleParam1;
		/** --cscale-param2=<value> */
		static std::string cscaleParam2;
		/** --dscale-param1=<value> */
		static std::string dscaleParam1;
		/** --dscale-param2=<value> */
		static std::string dscaleParam2;
		/** --tscale-param1=<value> */
		static std::string tscaleParam1;
		/** --tscale-param2=<value> */
		static std::string tscaleParam2;
		/** --scale-blur=<value> */
		static std::string scaleBlur;
		/** --scale-wblur=<value> */
		static std::string scaleWblur;
		/** --cscale-blur=<value> */
		static std::string cscaleBlur;
		/** --cscale-wblur=<value> */
		static std::string cscaleWblur;
		/** --dscale-blur=<value> */
		static std::string dscaleBlur;
		/** --dscale-wblur=<value> */
		static std::string dscaleWblur;
		/** --tscale-blur=<value> */
		static std::string tscaleBlur;
		/** --tscale-wblur=<value> */
		static std::string tscaleWblur;
		/** --scale-clamp=<0.0-1.0> */
		static std::string scaleClamp;
		/** --cscale-clamp */
		static std::string cscaleClamp;
		/** --dscale-clamp */
		static std::string dscaleClamp;
		/** --tscale-clamp */
		static std::string tscaleClamp;
		/** --scale-cutoff=<value> */
		static std::string scaleCutoff;
		/** --cscale-cutoff=<value> */
		static std::string cscaleCutoff;
		/** --dscale-cutoff=<value> */
		static std::string dscaleCutoff;
		/** --scale-taper=<value> */
		static std::string scaleTaper;
		/** --scale-wtaper=<value> */
		static std::string scaleWtaper;
		/** --dscale-taper=<value> */
		static std::string dscaleTaper;
		/** --dscale-wtaper=<value> */
		static std::string dscaleWtaper;
		/** --cscale-taper=<value> */
		static std::string cscaleTaper;
		/** --cscale-wtaper=<value> */
		static std::string cscaleWtaper;
		/** --tscale-taper=<value> */
		static std::string tscaleTaper;
		/** --tscale-wtaper=<value> */
		static std::string tscaleWtaper;
		/** --scale-radius=<value> */
		static std::string scaleRadius;
		/** --cscale-radius=<value> */
		static std::string cscaleRadius;
		/** --dscale-radius=<value> */
		static std::string dscaleRadius;
		/** --tscale-radius=<value> */
		static std::string tscaleRadius;
		/** --scale-antiring=<value> */
		static std::string scaleAntiring;
		/** --cscale-antiring=<value> */
		static std::string cscaleAntiring;
		/** --dscale-antiring=<value> */
		static std::string dscaleAntiring;
		/** --tscale-antiring=<value> */
		static std::string tscaleAntiring;
		/** --scale-window=<window> */
		static std::string scaleWindow;
		/** --cscale-window=<window> */
		static std::string cscaleWindow;
		/** --dscale-window=<window> */
		static std::string dscaleWindow;
		/** --tscale-window=<window> */
		static std::string tscaleWindow;
		/** --scale-wparam=<window> */
		static std::string scaleWparam;
		/** --cscale-wparam=<window> */
		static std::string cscaleWparam;
		/** --tscale-wparam=<window> */
		static std::string tscaleWparam;
		/** --scaler-lut-size=<4..10> */
		static std::string scalerLutSize;
		/** --scaler-resizes-only */
		static std::string scalerResizesOnly;
		/** --linear-scaling */
		static std::string linearScaling;
		/** --correct-downscaling */
		static std::string correctDownscaling;
		/** --interpolation */
		static std::string interpolation;
		/** --interpolation-threshold=<0..1 */
		static std::string interpolationThreshold;
		/** --opengl-pbo */
		static std::string openglPbo;
		/** --dither-depth=<N|no|auto> */
		static std::string ditherDepth;
		/** --dither-size-fruit=<2-8> */
		static std::string ditherSizeFruit;
		/** --dither=<fruit|ordered|no> */
		static std::string dither;
		/** --temporal-dither */
		static std::string temporalDither;
		/** --temporal-dither-period=<1-128> */
		static std::string temporalDitherPeriod;
		/** --gpu-debug */
		static std::string gpuDebug;
		/** --opengl-swapinterval=<n> */
		static std::string openglSwapinterval;
		/** --vulkan-swap-mode=<mode> */
		static std::string vulkanSwapMode;
		/** --vulkan-queue-count=<1..8> */
		static std::string vulkanQueueCount;
		/** --d3d11-warp=<yes|no|auto> */
		static std::string d3d11Warp;
		/** --d3d11-feature-level=<12_1|12_0|11_1|11_0|10_1|10_0|9_3|9_2|9_1> */
		static std::string d3d11FeatureLevel;
		/** --d3d11-flip=<yes|no> */
		static std::string d3d11Flip;
		/** --d3d11-sync-interval=<0..4> */
		static std::string d3d11SyncInterval;
		/** --d3d11va-zero-copy=<yes|no> */
		static std::string d3d11vaZeroCopy;
		/** --spirv-compiler=<compiler> */
		static std::string spirvCompiler;
		/** --glsl-shaders=<file-list> */
		static std::string glslShaders;
		/** --glsl-shader=<file> */
		static std::string glslShader;
		/** --deband */
		static std::string deband;
		/** --deband-iterations=<1..16> */
		static std::string debandIterations;
		/** --deband-threshold=<0..4096> */
		static std::string debandThreshold;
		/** --deband-range=<1..64> */
		static std::string debandRange;
		/** --deband-grain=<0..4096> */
		static std::string debandGrain;
		/** --sigmoid-upscaling */
		static std::string sigmoidUpscaling;
		/** --sigmoid-center */
		static std::string sigmoidCenter;
		/** --sigmoid-slope */
		static std::string sigmoidSlope;
		/** --sharpen=<value> */
		static std::string sharpen;
		/** --opengl-glfinish */
		static std::string openglGlfinish;
		/** --opengl-waitvsync */
		static std::string openglWaitvsync;
		/** --opengl-dwmflush=<no|windowed|yes|auto> */
		static std::string openglDwmflush;
		/** --angle-d3d11-feature-level=<11_0|10_1|10_0|9_3> */
		static std::string angleD3d11FeatureLevel;
		/** --angle-d3d11-warp=<yes|no|auto> */
		static std::string angleD3d11Warp;
		/** --angle-egl-windowing=<yes|no|auto> */
		static std::string angleEglWindowing;
		/** --angle-flip=<yes|no> */
		static std::string angleFlip;
		/** --angle-renderer=<d3d9|d3d11|auto> */;
		static std::string angleRenderer;
		/** --cocoa-force-dedicated-gpu=<yes|no> */
		static std::string cocoaForceDedicatedGpu;
		/** --swapchain-depth=<N> */
		static std::string swapchainDepth;
		/** --gpu-sw */
		static std::string gpuSw;
		/** --gpu-context=<sys> */
		static std::string gpuContext;
		/** --gpu-api=<type> */
		static std::string gpuApi;
		/** --opengl-es=<mode> */
		static std::string openglEs;
		/** --opengl-restrict=<version> */
		static std::string openglRestrict;
		/** --fbo-format=<fmt> */
		static std::string fboFormat;
		/** --gamma-factor=<0.1..2.0> */
		static std::string gammaFactor;
		/** --gamma-auto */
		static std::string gammaAuto;
		/** --target-prim=<value> */
		static std::string targetPrim;
		/** --target-trc=<value> */
		static std::string targetTrc;
		/** --tone-mapping=<value> */
		static std::string toneMapping;
		/** --tone-mapping-param=<value> */
		static std::string toneMappingParam;
		/** --hdr-compute-peak */
		static std::string hdrComputePeak;
		/** --tone-mapping-desaturate=<value> */
		static std::string toneMappingDesaturate;
		/** --gamut-warning */
		static std::string gamutWarning;
		/** --use-embedded-icc-profile */
		static std::string useEmbeddedIccProfile;
		/** --icc-profile=<file> */
		static std::string iccProfile;
		/** --icc-profile-auto */
		static std::string iccProfileAuto;
		/** --icc-cache-dir=<dirname> */
		static std::string iccCacheDir;
		/** --icc-intent=<value> */
		static std::string iccIntent;
		/** --icc-3dlut-size=<r>x<g>x<b> */
		static std::string icc3dlutSize;
		/** --icc-contrast=<0-100000> */
		static std::string iccContrast;
		/** --blend-subtitles=<yes|video|no> */
		static std::string blendSubtitles;
		/** --alpha=<blend-tiles|blend|yes|no> */
		static std::string alpha;
		/** --opengl-rectangle-textures */
		static std::string openglRectangleTextures;
		/** --background=<color> */
		static std::string background;
		/** --gpu-tex-pad-x */
		static std::string gpuTexPadX;
		/** --gpu-tex-pad-y */
		static std::string gpuTexPadY;
		/** --opengl-early-flush=<yes|no|auto> */
		static std::string openglEarlyFlush;
		/** --gpu-dumb-mode=<yes|no|auto> */
		static std::string gpuDumbMode;
		/** --gpu-shader-cache-dir=<dirname> */
		static std::string gpuShaderCacheDir;
		/** --cuda-decode-device=<auto|0..> */
		static std::string cudaDecodeDevice;
	};
	
	struct Miscellaneous {
		/** --display-tags=tag1 */
		static std::string displayTags;
		/** --mc=<seconds/frame> */
		static std::string mc;
		/** --autosync=<factor> */
		static std::string autosync;
		/** --video-sync=<audio|...> */
		static std::string videoSync;
		/** --video-sync-max-video-change=<value> */
		static std::string videoSyncMaxVideoChange;
		/** --video-sync-max-audio-change=<value> */
		static std::string videoSyncMaxAudioChange;
		/** --video-sync-adrop-size=<value> */
		static std::string videoSyncAdropSize;
		/** --mf-fps=<value> */
		static std::string mfFps;
		/** --mf-type=<value> */
		static std::string mfType;
		/** --stream-dump=<destination-filename> */
		static std::string streamDump;
		/** --stream-lavf-o=opt1=value1 */
		static std::string streamLavfO;
		/** --vo-mmcss-profile=<name> */
		static std::string voMmcssProfile;
		/** --priority=<prio> */
		static std::string priority;
		/** --force-media-title=<string> */
		static std::string forceMediaTitle;
		/** --external-files=<file-list> */
		static std::string externalFiles;
		/** --external-file=<file> */
		static std::string externalFile;
		/** --autoload-files=<yes|no> */
		static std::string autoloadFiles;
		/** --record-file=<file> */
		static std::string recordFile;
		/** --lavfi-complex=<string> */
		static std::string lavfiComplex;
	};
}

struct  MPVProperty{
	/** audio-speed-correction */
	static std::string audioSpeedCorrection;
	/** video-speed-correction */
	static std::string videoSpeedCorrection;
	/** display-sync-active */
	static std::string displaySyncActive;
		/** filename */
	static std::string filename;
		/** filename/no-ext */
	static std::string filenameNoExt;
		/** file-size */
	static std::string fileSize;
		/** estimated-frame-count */
	static std::string estimatedFrameCount;
		/** estimated-frame-number */
	static std::string estimatedFrameNumber;
		/** path */
	static std::string path;
		/** media-title */
	static std::string mediaTitle;
		/** file-format */
	static std::string fileFormat;
		/** current-demuxer */
	static std::string currentDemuxer;
		/** stream-path */
	static std::string streamPath;;
		/** stream-pos */
	static std::string streamPos;
		/** stream-end */
	static std::string streamEnd;
		/** duration */
	static std::string duration;
		/** avsync */
	static std::string avsync;
		/** total-avsync-change */
	static std::string totalAvsyncChange;
		/** decoder-frame-drop-count */
	static std::string decoderFrameDropCount;
		/** frame-drop-count */
	static std::string frameDropCount;
		/** mistimed-frame-count */
	static std::string mistimedFrameCount;
		/** vsync-ratio */
	static std::string vsyncRatio;
		/** vo-delayed-frame-count */
	static std::string voDelayedFrameCount;
		/** percent-pos */
	static std::string percentPos;
		/** time-pos */
	static std::string timePos;
		/** time-start */
	static std::string timeStart;
		/** time-remaining */
	static std::string timeRemaining;
		/** audio-pts */
	static std::string audioPts;
		/** playtime-remaining */
	static std::string playtimeRemaining;
		/** playback-time */
	static std::string playbackTime;
		/** chapter */
	static std::string chapter;
		/** edition */
	static std::string edition;
		/** disc-titles */
	static std::string discTitles;
		/** disc-titles/count */
	static std::string discTitlesCount;
		/** disc-titles/id */
	static std::string discTitlesId;
		/** disc-titles/length */
	static std::string discTitlesLength;
		/** disc-title-list */
	static std::string discTitleList;
		/** disc-title */
	static std::string discTitle;
		/** chapters */
	static std::string chapters;
		/** editions */
	static std::string editions;
		/** edition-list */
	static std::string editionList;
		/** edition-list/count */
	static std::string editionListCount;
			/** edition-list/N/id */
	static std::string editionListNId(int n);
		/** edition-list/N/default */
			static std::string editionListNDefault(int n);
		/** edition-list/N/title */
		static std::string editionListNTitle(int n);
		/** angle */
	static std::string angle;
		/** metadata */
	static std::string metadata;
		/** metadata/list/count */
	static std::string metadataListCount;
/** metadata/list/N/key */
	static std::string metadataListNKey(int n);
/** metadata/list/N/value */
	static std::string metadataListNValue(int n);
/** filtered-metadata */
	static std::string filteredMetadata;
/** chapter-metadata */
	static std::string chapterMetadata;
/** idle-active */
	static std::string idleActive;
/** core-idle */
	static std::string coreIdle;
/** cache */
	static std::string cache;
/** cache-size */
	static std::string cacheSize;
/** cache-free */
	static std::string cacheFree;
/** cache-used */
	static std::string cacheUsed;
/** cache-speed */
	static std::string cacheSpeed;
/** cache-idle */
	static std::string cacheIdle;
/** demuxer-cache-duration */
	static std::string demuxerCacheDuration;
/** demuxer-cache-time */
	static std::string demuxerCacheTime;
/** demuxer-cache-idle */
	static std::string demuxerCacheIdle;
/** demuxer-cache-state */
	static std::string demuxerCacheState;
/** eof */
	static std::string eof;
/** underrun */
	static std::string underrun;
/** idle */
	static std::string idle;
/** total-bytes */
	static std::string totalBytes;
/** fw-bytes */
	static std::string fwBytes;
/** demuxer-via-network */
	static std::string demuxerViaNetwork;
/** demuxer-start-time */
	static std::string demuxerStartTime;
/** paused-for-cache */
	static std::string pausedForCache;
/** cache-buffering-state */
	static std::string cacheBufferingState;
/** eof-reached */
	static std::string eofReached;
/** seeking */
	static std::string seeking;
/** mixer-active */
	static std::string mixerActive;
/** ao-volume */
	static std::string aoVolume;
/** ao-mute */
	static std::string aoMute;
/** audio-codec */
	static std::string audioCodec;
/** audio-codec-name */
	static std::string audioCodecName;
/** audio-params */
	static std::string audioParams;
/** audio-params/format */
	static std::string audioParamsFormat;
/** audio-params/samplerate */
	static std::string audioParamsSamplerate;
/** audio-params/channels */
	static std::string audioParamsChannels;
/** audio-params/hr-channels */
	static std::string audioParamsHrChannels;
/** audio-params/channel-count */
	static std::string audioParamsChannelCount;
/** audio-out-params */
	static std::string audioOutParams;
/** colormatrix */
	static std::string colormatrix;
/** colormatrix-input-range */
	static std::string colormatrixInputRange;
/** colormatrix-primaries */
	static std::string colormatrixPrimaries;
/** hwdec */
	static std::string hwdec;
/** hwdec-current */
	static std::string hwdecCurrent;
/** hwdec-interop */
	static std::string hwdecInterop;
/** video-format */
	static std::string videoFormat;
/** video-codec */
	static std::string videoCodec;
/** width */
	static std::string width;
/** height */
	static std::string height;
/** video-params */
	static std::string videoParams;
/** video-params/pixelformat */
	static std::string videoParamsPixelformat;
/** video-params/average-bpp */
	static std::string videoParamsAverageBpp;
/** video-params/plane-depth */
	static std::string videoParamsPlaneDepth;
/** video-params/w */
	static std::string videoParamsW;
/** video-params/h */
	static std::string videoParamsH;
/** video-params/dw */
	static std::string videoParamsDw;
/** video-params/dh */
	static std::string videoParamsDh;
/** video-params/aspect */
	static std::string videoParamsAspect;
/** video-params/par */
	static std::string videoParamsPar;
/** video-params/colormatrix */
	static std::string videoParamsColormatrix;
/** video-params/colorlevels */
	static std::string videoParamsColorlevels;
/** video-params/primaries */
	static std::string videoParamsPrimaries;
/** video-params/gamma */
	static std::string videoParamsGamma;
/** video-params/sig-peak */
	static std::string videoParamsSigPeak;
/** video-params/light */
	static std::string videoParamsLight;
/** video-params/chroma-location */
	static std::string videoParamsChromaLocation;
/** video-params/rotate */
	static std::string videoParamsRotate;
/** video-params/stereo-in */
	static std::string videoParamsStereoIn;
/** dwidth */
	static std::string dwidth;
/** dheight */
	static std::string dheight;
/** video-dec-params */
	static std::string videoDecParams;
/** video-out-params */
	static std::string videoOutParams;
/** video-frame-info */
	static std::string videoFrameInfo;
/** container-fps */
	static std::string containerFps;
/** estimated-vf-fps */
	static std::string estimatedVfFps;
/** window-scale */
	static std::string windowScale;
/** window-minimized */
	static std::string windowMinimized;
/** display-names */
	static std::string displayNames;
/** display-fps */
	static std::string displayFps;
/** estimated-display-fps */
	static std::string estimatedDisplayFps;
/** vsync-jitter */
	static std::string vsyncJitter;
/** video-aspect */
	static std::string videoAspect;
/** osd-width */
	static std::string osdWidth;
/** osd-height */
	static std::string osdHeight;
/** osd-par */
	static std::string osdPar;
/** program */
	static std::string program;
/** dvb-channel */
	static std::string dvbChannel;
/** dvb-channel-name */
	static std::string dvbChannelName;
/** sub-text */
	static std::string subText;
/** tv-brightness */
	static std::string tvBrightness;
/** tv-contrast */
	static std::string tvContrast;
/** tv-saturation */
	static std::string tvSaturation;
/** tv-hue */
	static std::string tvHue;
/** playlist-pos */
	static std::string playlistPos;
/** playlist-pos-1 */
	static std::string playlistPos1;
/** playlist-count */
	static std::string playlistCount;
/** playlist */
	static std::string playlist;;
/** playlist/count */
	static std::string playlistCount2;
/** playlist/N/filename */
	static std::string playlistNFilename(int n);
/** playlist/N/current */
static std::string playlistNCurrent(int n);
/** playlist/N/playing */
static std::string playlistNPlaying(int n);
/** playlist/N/title */
static std::string playlistNTitle(int n);
/** track-list */
	static std::string trackList;
/** track-list/count */
	static std::string trackListCount;
		/** track-list/N/id */
	static std::string trackListNId(int index);
	///** track-list/N/type */
	static std::string trackListNType(int index);
	/** track-list/N/src-id */
	static std::string trackListNSrcId(int n);
	/** track-list/N/title */
	static std::string trackListNTitle(int n);
	/** track-list/N/lang */
	static std::string trackListNLang(int n);
	/** track-list/N/albumart */
	static std::string trackListNAlbumart(int n);
	/** track-list/N/default */
	static std::string trackListNDefault(int index);
	/** track-list/N/forced */
	static std::string trackListNForced(int n);
	/** track-list/N/codec */
	static std::string trackListNCodec(int n);
	/** track-list/N/external */
	static std::string trackListNExternal(int n);
	/** track-list/N/external-filename */
	static std::string trackListNExternalFilename(int n);
	/** track-list/N/selected */
	static std::string trackListNSelected(int n);
	/** track-list/N/ff-index */
	static std::string trackListNFfIndex(int n);
	/** track-list/N/decoder-desc */
	static std::string trackListNDecoderDesc(int n);
	/** track-list/N/demux-w */
	static std::string trackListNDemuxW(int n);
	/** track-list/N/demux-h */
	static std::string trackListNDemuxH(int n);
	/** track-list/N/demux-channel-count */
	static std::string trackListNDemuxChannelCount(int n);
	/** track-list/N/demux-channels */
	static std::string trackListNDemuxChannels(int n);
	/** track-list/N/demux-samplerate */
	static std::string trackListNDemuxSamplerate(int n);
	/** track-list/N/demux-fps */
	static std::string trackListNDemuxFps(int n);
	/** track-list/N/audio-channels */
	static std::string trackListNAudioChannels(int n);
	/** track-list/N/replaygain-track-peak */
	static std::string trackListNReplaygainTrackPeak(int n);
	/** track-list/N/replaygain-track-gain */
	static std::string trackListNReplaygainTrackGain(int n);
	/** track-list/N/replaygain-album-peak */
	static std::string trackListNReplaygainAlbumPeak(int n);
	/** track-list/N/replaygain-album-gain */
	static std::string trackListNReplaygainAlbumGain(int n);
	/** chapter-list */
static std::string chapterList;
/** chapter-list/count */
static std::string chapterListCount;
/** chapter-list/N/title */
static std::string chapterListNTitle(int n);
/** chapter-list/N/time */
static std::string chapterListNTime(int n);
/** af */
static std::string af;
/** vf */
static std::string vf;
/** seekable */
static std::string seekable;
/** partially-seekable */
static std::string partiallySeekable;
/** playback-abort */
static std::string playbackAbort;
/** cursor-autohide */
static std::string cursorAutohide;
/** osd-sym-cc */
static std::string osdSymCc;
/** osd-ass-cc */
static std::string osdAssCc;
/** vo-configured */
static std::string voConfigured;
/** vo-passes */
static std::string voPasses;
/** vo-passes/TYPE/count */
static std::string voPassesTYPECount;
/** vo-passes/TYPE/N/desc */
static std::string voPassesTYPENDesc(int n);
/** vo-passes/TYPE/N/last */
static std::string voPassesTYPENLast(int n);
/** vo-passes/TYPE/N/avg */
static std::string voPassesTYPENAvg(int n);
/** vo-passes/TYPE/N/peak */
static std::string voPassesTYPENPeak(int n);
/** vo-passes/TYPE/N/count */
static std::string voPassesTYPENCount(int n);
/** vo-passes/TYPE/N/samples/M */
static std::string voPassesTYPENSamplesM(int n);
/** video-bitrate */
static std::string videoBitrate;
/** audio-bitrate */
static std::string audioBitrate;
/** sub-bitrate */
static std::string subBitrate;
/** packet-video-bitrate */
static std::string packetVideoBitrate;
/** packet-audio-bitrate */
static std::string packetAudioBitrate;
/** packet-sub-bitrate */
static std::string packetSubBitrate;
/** audio-device-list */
static std::string audioDeviceList;
/** audio-device */
static std::string audioDevice;
/** current-vo */
static std::string currentVo;
/** current-ao */
static std::string currentAo;
/** working-directory */
static std::string workingDirectory;
/** protocol-list */
static std::string protocolList;
/** decoder-list */
static std::string decoderList;
/** family */
static std::string family;
/** codec */
static std::string codec;
/** driver */
static std::string driver;
/** description */
static std::string description;
/** encoder-list */
static std::string encoderList;
/** mpv-version */
static std::string mpvVersion;
/** mpv-configuration */
static std::string mpvConfiguration;
/** ffmpeg-version */
static std::string ffmpegVersion;
/** options/<name> */
static std::string options(std::string name);
/** file-local-options/<name> */
static std::string fileLocalOptions(std::string name);
/** option-info/<name> */
static std::string optionInfo(std::string name);
/** option-info/<name>/name */
static std::string optionInfoName(std::string name);
/** option-info/<name>/type */
static std::string optionInfoType(std::string name);
/** option-info/<name>/set-from-commandline */
static std::string optionInfoSetFromCommandline(std::string name);
/** option-info/<name>/set-locally */
static std::string optionInfoSetLocally(std::string name);
/** option-info/<name>/default-value */
static std::string optionInfoDefaultValue(std::string name);
/** option-info/<name>/min */
static std::string optionInfoMin(std::string name);
/** option-info/<name>/max */
static std::string optionInfoMax(std::string name);
/** option-info/<name>/choices */
static std::string optionInfoChoices(std::string name);
/** property-list */
static std::string propertyList;
/** profile-list */
static std::string profileList;
};





#endif // !MPV_DATA_DEFINE_H_

