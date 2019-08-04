#include"stdafx.h"
#include"MPVDataDefine.h"

/** ignore */
MPVCommand  MPVCommand::ignore = MPVCommand("ignore");
/** seek <seconds> [relative|absolute|absolute-percent|relative-percent|exact|keyframes] */
MPVCommand MPVCommand::seek = MPVCommand("seek");
/** revert-seek [mode] */
MPVCommand MPVCommand::revertSeek = MPVCommand("revert-seek");
/** frame-step */
MPVCommand MPVCommand::frameStep = MPVCommand("frame-step");
/** frame-back-step */
MPVCommand MPVCommand::frameBackStep = MPVCommand("frame-back-step");
/** set <property> "<value>" */
MPVCommand MPVCommand::set = MPVCommand("set");
/** add <property> [<value>] */
MPVCommand MPVCommand::add = MPVCommand("add");
/** cycle <property> [up|down] */
MPVCommand MPVCommand::cycle = MPVCommand("cycle");
/** multiply <property> <factor> */
MPVCommand MPVCommand::multiply = MPVCommand("multiply");
/** screenshot [subtitles|video|window|single|each-frame] */
MPVCommand MPVCommand::screenshot = MPVCommand("screenshot");
/** screenshot-to-file "<filename>" [subtitles|video|window] */
MPVCommand MPVCommand::screenshotToFile = MPVCommand("screenshot-to-file");
/** playlist-next [weak|force] */
MPVCommand MPVCommand::playlistNext = MPVCommand("playlist-next");
/** playlist-prev [weak|force] */
MPVCommand MPVCommand::playlistPrev = MPVCommand("playlist-prev");
/** loadfile "<file>" [replace|append|append-play [options]] */
MPVCommand MPVCommand::loadfile = MPVCommand("loadfile");
/** loadlist "<playlist>" [replace|append] */
MPVCommand MPVCommand::loadlist = MPVCommand("loadlist");
/** playlist-clear */
MPVCommand MPVCommand::playlistClear = MPVCommand("playlist-clear");
/** playlist-remove current|<index> */
MPVCommand MPVCommand::playlistRemove = MPVCommand("playlist-remove");
/** playlist-move <index1> <index2> */
MPVCommand MPVCommand::playlistMove = MPVCommand("playlist-move");
/** playlist-shuffle */
MPVCommand MPVCommand::playlistShuffle = MPVCommand("playlist-shuffle");
/** run "command" "arg1" "arg2" ... */
MPVCommand MPVCommand::run = MPVCommand("run");
/** quit [<code>] */
MPVCommand MPVCommand::quit = MPVCommand("quit");
/** quit-watch-later [<code>] */
MPVCommand MPVCommand::quitWatchLater = MPVCommand("quit-watch-later");
/** sub-add "<file>" [<flags> [<title> [<lang>]]] */
MPVCommand MPVCommand::subAdd = MPVCommand("sub-add");
/** sub-remove [<id>] */
MPVCommand MPVCommand::subRemove = MPVCommand("sub-remove");
/** sub-reload [<id>] */
MPVCommand MPVCommand::subReload = MPVCommand("sub-reload");
/** sub-step <skip> */
MPVCommand MPVCommand::subStep = MPVCommand("sub-step");
/** sub-seek <skip> */
MPVCommand MPVCommand::subSeek = MPVCommand("sub-seek");
/** print-text "<string>" */
MPVCommand MPVCommand::printText = MPVCommand("print-text");
/** show-text "<string>" [<duration>|- [<level>]] */
MPVCommand MPVCommand::showText = MPVCommand("show-text");
/** expand-text "<string>" */
MPVCommand MPVCommand::expandText = MPVCommand("expand-text");
/** show-progress */
MPVCommand MPVCommand::showProgress = MPVCommand("show-progress");
/** write-watch-later-config */
MPVCommand MPVCommand::writeWatchLaterConfig = MPVCommand("write-watch-later-config");
/** stop */
MPVCommand MPVCommand::stop = MPVCommand("stop");
/** mouse <x> <y> [<button> [single|double]] */
MPVCommand MPVCommand::mouse = MPVCommand("mouse");
/** keypress <key_name> */
MPVCommand MPVCommand::keypress = MPVCommand("keypress");
/** keydown <key_name> */
MPVCommand MPVCommand::keydown = MPVCommand("keydown");
/** keyup [<key_name>] */
MPVCommand MPVCommand::keyup = MPVCommand("keyup");
/** audio-add "<file>" [<flags> [<title> [<lang>]]] */
MPVCommand MPVCommand::audioAdd = MPVCommand("audio-add");
/** audio-remove [<id>] */;
MPVCommand MPVCommand::audioRemove = MPVCommand("audio-remove");
/** audio-reload [<id>] */
MPVCommand MPVCommand::audioReload = MPVCommand("audio-reload");
/** rescan-external-files [<mode>] */
MPVCommand MPVCommand::rescanExternalFiles = MPVCommand("rescan-external-files");
/** af set|add|toggle|del|clr "filter1=params,filter2,..." */
MPVCommand MPVCommand::af = MPVCommand("af");
/** vf set|add|toggle|del|clr "filter1=params,filter2,..." */
MPVCommand MPVCommand::vf = MPVCommand("vf");
/** cycle-values ["!reverse"] <property> "<value1>" "<value2>" ... */
MPVCommand MPVCommand::cycleValues = MPVCommand("cycle-values");
/** enable-section "<section>" [flags] */
MPVCommand MPVCommand::enableSection = MPVCommand("enable-section");
/** disable-section "<section>" */
MPVCommand MPVCommand::disableSection = MPVCommand("disable-section");
/** define-section "<section>" "<contents>" [default|force] */
MPVCommand MPVCommand::defineSection = MPVCommand("define-section");
/** overlay-add <id> <x> <y> "<file>" <offset> "<fmt>" <w> <h> <stride> */
MPVCommand MPVCommand::overlayAdd = MPVCommand("overlay-add");
/** overlay-remove <id> */
MPVCommand MPVCommand::overlayRemove = MPVCommand("overlay-remove");
/** script-message "<arg1>" "<arg2>" ... */
MPVCommand MPVCommand::scriptMessage = MPVCommand("script-message");
/** script-message-to "<target>" "<arg1>" "<arg2>" ... */
MPVCommand MPVCommand::scriptMessageTo = MPVCommand("script-message-to");
/** script-binding "<name>" */
MPVCommand MPVCommand::scriptBinding = MPVCommand("script-binding");
/** ab-loop */
MPVCommand MPVCommand::abLoop = MPVCommand("ab-loop");
/** drop-buffers */
MPVCommand MPVCommand::dropBuffers = MPVCommand("drop-buffers");
/** screenshot-raw [subtitles|video|window] */
MPVCommand MPVCommand::screenshotRaw = MPVCommand("screenshot-raw");
/** vf-command "<label>" "<cmd>" "<args>" */
MPVCommand MPVCommand::vfCommand = MPVCommand("vf-command");
/** af-command "<label>" "<cmd>" "<args>" */
MPVCommand MPVCommand::afCommand = MPVCommand("af-command");
/** apply-profile "<name>" */
MPVCommand MPVCommand::applyProfile = MPVCommand("apply-profile");
/** load-script "<path>" */
MPVCommand MPVCommand::loadScript = MPVCommand("load-script");


//option
namespace MPVOption {
	
	/** --alang=<languagecode[ */
	std::string TrackSelection::alang = "alang";
	/** --slang=<languagecode[ */
	std::string TrackSelection::slang = "slang";
	/** --vlang=<...> */
	std::string TrackSelection::vlang = "vlang";
	/** --aid=<ID|auto|no> */
	std::string TrackSelection::aid = "aid";
	/** --sid=<ID|auto|no> */
	std::string TrackSelection::sid = "sid";
	/** --vid=<ID|auto|no> */
	std::string TrackSelection::vid = "vid";
	/** --ff-aid=<ID|auto|no> */
	std::string TrackSelection::ffAid = "ff-aid";
	/** --ff-sid=<ID|auto|no> */
	std::string TrackSelection::ffSid = "ff-sid";
	/** --ff-vid=<ID|auto|no> */
	std::string TrackSelection::ffVid = "ff-vid";
	/** --edition=<ID|auto> */
	std::string TrackSelection::edition = "edition";
	/** --track-auto-selection=<yes|no> */
	std::string TrackSelection::trackAutoSelection = "track-auto-selection";


	/** --start=<relative time> */
	std::string  PlaybackControl::start = "start";
	/** --end=<time> */
	std::string  PlaybackControl::end = "end";
	/** --length=<relative time> */
	std::string  PlaybackControl::length = "length";
	/** --rebase-start-time=<yes|no> */
	std::string  PlaybackControl::rebaseStartTime = "rebase-start-time";
	/** --speed=<0.01-100> */
	std::string  PlaybackControl::speed = "speed";
	/** --pause */
	std::string  PlaybackControl::pause = "pause";
	/** --shuffle */
	std::string  PlaybackControl::shuffle = "shuffle";
	/** --chapter=<start[-end]> */
	std::string  PlaybackControl::chapter = "chapter";
	/** --playlist-start=<auto|index> */
	std::string  PlaybackControl::playlistStart = "playlist-start";
	/** --playlist=<filename> */
	std::string  PlaybackControl::playlist = "playlist";
	/** --chapter-merge-threshold=<number> */
	std::string  PlaybackControl::chapterMergeThreshold = "chapter-merge-threshold";
	/** --chapter-seek-threshold=<seconds> */
	std::string  PlaybackControl::chapterSeekThreshold = "chapter-seek-threshold";
	/** --hr-seek=<no|absolute|yes> */
	std::string  PlaybackControl::hrSeek = "hr-seek";
	/** --hr-seek-demuxer-offset=<seconds> */
	std::string  PlaybackControl::hrSeekDemuxerOffset = "hr-seek-demuxer-offset";
	/** --hr-seek-framedrop=<yes|no> */
	std::string  PlaybackControl::hrSeekFramedrop = "hr-seek-framedrop";
	/** --index=<mode> */
	std::string  PlaybackControl::index = "index";
	/** --load-unsafe-playlists */
	std::string  PlaybackControl::loadUnsafePlaylists = "load-unsafe-playlists";
	/** --access-references=<yes|no> */
	std::string  PlaybackControl::accessReferences = "access-references";
	/** --loop-playlist=<N|inf|force|no> */
	std::string  PlaybackControl::loopPlaylist = "loop-playlist";
	/** --loop-file=<N|inf|no> */
	std::string  PlaybackControl::loopFile = "loop-file";
	/** --loop=<N|inf|no> */
	std::string  PlaybackControl::loop = "loop";
	/** --ab-loop-a=<time> */
	std::string  PlaybackControl::abLoopA = "ab-loop-a";
	/** --ab-loop-b=<time> */
	std::string  PlaybackControl::abLoopB = "ab-loop-b";
	/** --ordered-chapters */
	std::string  PlaybackControl::orderedChapters = "ordered-chapters";
	/** --no-ordered-chapters */
	std::string  PlaybackControl::noOrderedChapters = "no-ordered-chapters";
	/** --ordered-chapters-files=<playlist-file> */
	std::string  PlaybackControl::orderedChaptersFiles = "ordered-chapters-files";
	/** --chapters-file=<filename> */
	std::string  PlaybackControl::chaptersFile = "chapters-file";
	/** --sstep=<sec> */
	std::string  PlaybackControl::sstep = "sstep";
	/** --stop-playback-on-init-failure=<yes|no> */
	std::string  PlaybackControl::stopPlaybackOnInitFailure = "stop-playback-on-init-failure";

	
	/** --help */
	std::string  ProgramBehavior::help = "help";
	/** --h */
	std::string  ProgramBehavior::h = "h";
	/** --version */
	std::string  ProgramBehavior::version = "version";
	/** --no-config */
	std::string  ProgramBehavior::noConfig = "no-config";
	/** --list-options */
	std::string  ProgramBehavior::listOptions = "list-options";
	/** --list-properties */
	std::string  ProgramBehavior::listProperties = "list-properties";
	/** --list-protocols */
	std::string  ProgramBehavior::listProtocols = "list-protocols";
	/** --log-file=<path> */
	std::string  ProgramBehavior::logFile = "log-file";
	/** --config-dir=<path> */
	std::string  ProgramBehavior::configDir = "config-dir";
	/** --save-position-on-quit */
	std::string  ProgramBehavior::savePositionOnQuit = "save-position-on-quit";
	/** --dump-stats=<filename> */
	std::string  ProgramBehavior::dumpStats = "dump-stats";
	/** --idle=<no|yes|once> */
	std::string  ProgramBehavior::idle = "idle";
	/** --include=<configuration-file> */
	std::string  ProgramBehavior::include = "include";
	/** --load-scripts=<yes|no> */
	std::string  ProgramBehavior::loadScripts = "load-scripts";
	/** --script=<filename> */
	std::string  ProgramBehavior::script = "script";
	/** --script-opts=key1=value1 */
	std::string  ProgramBehavior::scriptOpts = "script-opts";
	/** --merge-files */
	std::string  ProgramBehavior::mergeFiles = "merge-files";
	/** --no-resume-playback */
	std::string  ProgramBehavior::noResumePlayback = "no-resume-playback";
	/** --profile=<profile1 */
	std::string  ProgramBehavior::profile = "profile";
	/** --reset-on-next-file=<all|option1 */
	std::string  ProgramBehavior::resetOnNextFile = "reset-on-next-file";
	/** --write-filename-in-watch-later-config */
	std::string  ProgramBehavior::writeFilenameInWatchLaterConfig = "write-filename-in-watch-later-config";
	/** --ignore-path-in-watch-later-config */
	std::string  ProgramBehavior::ignorePathInWatchLaterConfig = "ignore-path-in-watch-later-config";
	/** --show-profile=<profile> */
	std::string  ProgramBehavior::showProfile = "show-profile";
	/** --use-filedir-conf */
	std::string  ProgramBehavior::useFiledirConf = "use-filedir-conf";
	/** --ytdl */
	std::string  ProgramBehavior::ytdl = "ytdl";
	/** --no-ytdl */
	std::string  ProgramBehavior::noYtdl = "no-ytdl";
	/** --ytdl-format=<best|worst|mp4|webm|...> */
	std::string  ProgramBehavior::ytdlFormat = "ytdl-format";
	/** --ytdl-raw-options=<key>=<value>[ */
	std::string  ProgramBehavior::ytdlRawOptions = "ytdl-raw-options";
	/** --load-stats-overlay=<yes|no> */
	std::string  ProgramBehavior::loadStatsOverlay = "load-stats-overlay";
	/** --player-operation-mode=<cplayer|pseudo-gui> */
	std::string  ProgramBehavior::playerOperationMode = "player-operation-mode";


	/** --vo=<driver> */
	std::string  Video::vo = "vo";
	/** --vd=<...> */
	std::string  Video::vd = "vd";
	/** --vf=<filter1[=parameter1:parameter2:...] */
	std::string  Video::vf = "vf";
	/** --untimed */
	std::string  Video::untimed = "untimed";
	/** --framedrop=<mode> */
	std::string  Video::framedrop = "framedrop";
	/** --display-fps=<fps> */
	std::string  Video::displayFps = "display-fps";
	/** --hwdec=<api> */
	std::string  Video::hwdec = "hwdec";
	/** --gpu-hwdec-interop=<auto|all|no|name> */
	std::string  Video::gpuHwdecInterop = "gpu-hwdec-interop";
	/** --hwdec-image-format=<name> */
	std::string  Video::hwdecImageFormat = "hwdec-image-format";
	/** --videotoolbox-format=<name> */
	std::string  Video::videotoolboxFormat = "videotoolbox-format";
	/** --panscan=<0.0-1.0> */
	std::string  Video::panscan = "panscan";
	/** --video-aspect=<ratio|no> */
	std::string  Video::videoAspect = "video-aspect";
	/** --video-aspect-method=<bitstream|container> */
	std::string  Video::videoAspectMethod = "video-aspect-method";
	/** --video-unscaled=<no|yes|downscale-big> */
	std::string  Video::videoUnscaled = "video-unscaled";
	/** --video-pan-x=<value> */
	std::string  Video::videoPanX = "video-pan-x";
	/** --video-pan-y=<value> */
	std::string  Video::videoPanY = "video-pan-y";
	/** --video-rotate=<0-359|no> */
	std::string  Video::videoRotate = "video-rotate";
	/** --video-stereo-mode=<no|mode> */
	std::string  Video::videoStereoMode = "video-stereo-mode";
	/** --video-zoom=<value> */
	std::string  Video::videoZoom = "video-zoom";
	/** --video-align-x=<-1-1> */
	std::string  Video::videoAlignX = "video-align-x";
	/** --video-align-y=<-1-1> */
	std::string  Video::videoAlignY = "video-align-y";
	/** --correct-pts */
	std::string  Video::correctPts = "correct-pts";
	/** --no-correct-pts */
	std::string  Video::noCorrectPts = "no-correct-pts";
	/** --fps=<float> */
	std::string  Video::fps = "fps";
	/** --deinterlace=<yes|no> */
	std::string  Video::deinterlace = "deinterlace";
	/** --frames=<number> */
	std::string  Video::frames = "frames";
	/** --video-output-levels=<outputlevels> */
	std::string  Video::videoOutputLevels = "video-output-levels";
	/** --hwdec-codecs=<codec1 */
	std::string  Video::hwdecCodecs = "hwdec-codecs";
	/** --vd-lavc-check-hw-profile=<yes|no> */
	std::string  Video::vdLavcCheckHwProfile = "vd-lavc-check-hw-profile";
	/** --vd-lavc-software-fallback=<yes|no|N> */
	std::string  Video::vdLavcSoftwareFallback = "vd-lavc-software-fallback";
	/** --vd-lavc-dr=<yes|no> */
	std::string  Video::vdLavcDr = "vd-lavc-dr";
	/** --vd-lavc-bitexact */
	std::string  Video::vdLavcBitexact = "vd-lavc-bitexact";
	/** --vd-lavc-fast */
	std::string  Video::vdLavcFast = "vd-lavc-fast";
	/** --vd-lavc-o=<key>=<value>[ */
	std::string  Video::vdLavcO = "vd-lavc-o";
	/** --vd-lavc-show-all=<yes|no> */
	std::string  Video::vdLavcShowAll = "vd-lavc-show-all";
	/** --vd-lavc-skiploopfilter=<skipvalue> (H.264 only) */
	std::string  Video::vdLavcSkiploopfilter = "vd-lavc-skiploopfilter";
	/** --vd-lavc-skipidct=<skipvalue> (MPEG-1/2 only) */
	std::string  Video::vdLavcSkipidct = "vd-lavc-skipidct";
	/** --vd-lavc-skipframe=<skipvalue> */
	std::string  Video::vdLavcSkipframe = "vd-lavc-skipframe";
	/** --vd-lavc-framedrop=<skipvalue> */
	std::string  Video::vdLavcFramedrop = "vd-lavc-framedrop";
	/** --vd-lavc-threads=<N> */
	std::string  Video::vdLavcThreads = "vd-lavc-threads";


	/** --audio-pitch-correction=<yes|no> */
	std::string  Audio::audioPitchCorrection = "audio-pitch-correction";
	/** --audio-device=<name> */
	std::string  Audio::audioDevice = "audio-device";
	/** --audio-exclusive=<yes|no> */
	std::string  Audio::audioExclusive = "audio-exclusive";
	/** --audio-fallback-to-null=<yes|no> */
	std::string  Audio::audioFallbackToNull = "audio-fallback-to-null";
	/** --ao=<driver> */
	std::string  Audio::ao = "ao";
	/** --af=<filter1[=parameter1:parameter2:...] */
	std::string  Audio::af = "af";
	/** --audio-spdif=<codecs> */
	std::string  Audio::audioSpdif = "audio-spdif";
	/** --ad=<decoder1 */
	std::string  Audio::ad = "ad";
	/** --volume=<value> */
	std::string  Audio::volume = "volume";
	/** --replaygain=<no|track|album> */
	std::string  Audio::replaygain = "replaygain";
	/** --replaygain-preamp=<db> */
	std::string  Audio::replaygainPreamp = "replaygain-preamp";
	/** --replaygain-clip=<yes|no> */
	std::string  Audio::replaygainClip = "replaygain-clip";
	/** --replaygain-fallback=<db> */
	std::string  Audio::replaygainFallback = "replaygain-fallback";
	/** --audio-delay=<sec> */
	std::string  Audio::audioDelay = "audio-delay";
	/** --mute=<yes|no|auto> */
	std::string  Audio::mute = "mute";
	/** --softvol=<no|yes|auto> */
	std::string  Audio::softvol = "softvol";
	/** --audio-demuxer=<[+]name> */
	std::string  Audio::audioDemuxer = "audio-demuxer";
	/** --ad-lavc-ac3drc=<level> */
	std::string  Audio::adLavcAc3drc = "ad-lavc-ac3drc";
	/** --ad-lavc-downmix=<yes|no> */
	std::string  Audio::adLavcDownmix = "ad-lavc-downmix";
	/** --ad-lavc-threads=<0-16> */
	std::string  Audio::adLavcThreads = "ad-lavc-threads";
	/** --ad-lavc-o=<key>=<value>[ */
	std::string  Audio::adLavcO = "ad-lavc-o";
	/** --ad-spdif-dtshd=<yes|no> */
	std::string  Audio::adSpdifDtshd = "ad-spdif-dtshd";
	/** --dtshd */
	std::string  Audio::dtshd = "dtshd";
	/** --no-dtshd */
	std::string  Audio::noDtshd = "no-dtshd";
	/** --audio-channels=<auto-safe|auto|layouts> */
	std::string  Audio::audioChannels = "audio-channels";
	/** --audio-normalize-downmix=<yes|no> */
	std::string  Audio::audioNormalizeDownmix = "audio-normalize-downmix";
	/** --audio-display=<no|attachment> */
	std::string  Audio::audioDisplay = "audio-display";
	/** --audio-files=<files> */
	std::string  Audio::audioFiles = "audio-files";
	/** --audio-file=<file> */
	std::string  Audio::audioFile = "audio-file";
	/** --audio-format=<format> */
	std::string  Audio::audioFormat = "audio-format";
	/** --audio-samplerate=<Hz> */
	std::string  Audio::audioSamplerate = "audio-samplerate";
	/** --gapless-audio=<no|yes|weak> */
	std::string  Audio::gaplessAudio = "gapless-audio";
	/** --initial-audio-sync */
	std::string  Audio::initialAudioSync = "initial-audio-sync";
	/** --no-initial-audio-sync */
	std::string  Audio::noInitialAudioSync = "no-initial-audio-sync";
	/** --volume-max=<100.0-1000.0> */
	std::string  Audio::volumeMax = "volume-max";
	/** --softvol-max=<...> */
	std::string  Audio::softvolMax = "softvol-max";
	/** --audio-file-auto=<no|exact|fuzzy|all> */
	std::string  Audio::audioFileAuto = "audio-file-auto";
	/** --no-audio-file-auto */
	std::string  Audio::noAudioFileAuto = "no-audio-file-auto";
	/** --audio-file-paths=<path1:path2:...> */
	std::string  Audio::audioFilePaths = "audio-file-paths";
	/** --audio-client-name=<name> */
	std::string  Audio::audioClientName = "audio-client-name";
	/** --audio-buffer=<seconds> */
	std::string  Audio::audioBuffer = "audio-buffer";
	/** --audio-stream-silence=<yes|no> */
	std::string  Audio::audioStreamSilence = "audio-stream-silence";
	/** --audio-wait-open=<secs> */
	std::string  Audio::audioWaitOpen = "audio-wait-open";

	

	/** --sub-demuxer=<[+]name> */
	std::string  Subtitles::subDemuxer = "sub-demuxer";
	/** --sub-delay=<sec> */
	std::string  Subtitles::subDelay = "sub-delay";
	/** --sub-files=<file-list> */
	std::string  Subtitles::subFiles = "sub-files";
	/** --sub-file=<filename> */
	std::string  Subtitles::subFile = "sub-file";
	/** --secondary-sid=<ID|auto|no> */
	std::string  Subtitles::secondarySid = "secondary-sid";
	/** --sub-scale=<0-100> */
	std::string  Subtitles::subScale = "sub-scale";
	/** --sub-scale-by-window=<yes|no> */
	std::string  Subtitles::subScaleByWindow = "sub-scale-by-window";
	/** --sub-scale-with-window=<yes|no> */
	std::string  Subtitles::subScaleWithWindow = "sub-scale-with-window";
	/** --sub-ass-scale-with-window=<yes|no> */
	std::string  Subtitles::subAssScaleWithWindow = "sub-ass-scale-with-window";
	/** --embeddedfonts */
	std::string  Subtitles::embeddedfonts = "embeddedfonts";
	/** --no-embeddedfonts */
	std::string  Subtitles::noEmbeddedfonts = "no-embeddedfonts";
	/** --sub-pos=<0-100> */
	std::string  Subtitles::subPos = "sub-pos";
	/** --sub-speed=<0.1-10.0> */
	std::string  Subtitles::subSpeed = "sub-speed";
	/** --sub-ass-force-style=<[Style.]Param=Value[ */
	std::string  Subtitles::subAssForceStyle = "sub-ass-force-style";
	/** --sub-ass-hinting=<none|light|normal|native> */
	std::string  Subtitles::subAssHinting = "sub-ass-hinting";
	/** --sub-ass-line-spacing=<value> */
	std::string  Subtitles::subAssLineSpacing = "sub-ass-line-spacing";
	/** --sub-ass-shaper=<simple|complex> */
	std::string  Subtitles::subAssShaper = "sub-ass-shaper";
	/** --sub-ass-styles=<filename> */
	std::string  Subtitles::subAssStyles = "sub-ass-styles";
	/** --sub-ass-override=<yes|no|force|scale|strip> */
	std::string  Subtitles::subAssOverride = "sub-ass-override";
	/** --sub-ass-force-margins */
	std::string  Subtitles::subAssForceMargins = "sub-ass-force-margins";
	/** --sub-use-margins */
	std::string  Subtitles::subUseMargins = "sub-use-margins";
	/** --sub-ass-vsfilter-aspect-compat=<yes|no> */
	std::string  Subtitles::subAssVsfilterAspectCompat = "sub-ass-vsfilter-aspect-compat";
	/** --sub-ass-vsfilter-blur-compat=<yes|no> */
	std::string  Subtitles::subAssVsfilterBlurCompat = "sub-ass-vsfilter-blur-compat";
	/** --sub-ass-vsfilter-color-compat=<basic|full|force-601|no> */
	std::string  Subtitles::subAssVsfilterColorCompat = "sub-ass-vsfilter-color-compat";
	/** --stretch-dvd-subs=<yes|no> */
	std::string  Subtitles::stretchDvdSubs = "stretch-dvd-subs";
	/** --stretch-image-subs-to-screen=<yes|no> */
	std::string  Subtitles::stretchImageSubsToScreen = "stretch-image-subs-to-screen";
	/** --image-subs-video-resolution=<yes|no> */
	std::string  Subtitles::imageSubsVideoResolution = "image-subs-video-resolution";
	/** --sub-ass */
	std::string  Subtitles::subAss = "sub-ass";
	/** --no-sub-ass */
	std::string  Subtitles::noSubAss = "no-sub-ass";
	/** --sub-auto=<no|exact|fuzzy|all> */
	std::string  Subtitles::subAuto = "sub-auto";
	/** --no-sub-auto */
	std::string  Subtitles::noSubAuto = "no-sub-auto";
	/** --sub-codepage=<codepage> */
	std::string  Subtitles::subCodepage = "sub-codepage";
	/** --sub-fix-timing=<yes|no> */
	std::string  Subtitles::subFixTiming = "sub-fix-timing";
	/** --sub-forced-only */
	std::string  Subtitles::subForcedOnly = "sub-forced-only";
	/** --sub-fps=<rate> */
	std::string  Subtitles::subFps = "sub-fps";
	/** --sub-gauss=<0.0-3.0> */
	std::string  Subtitles::subGauss = "sub-gauss";
	/** --sub-gray */
	std::string  Subtitles::subGray = "sub-gray";
	/** --sub-paths=<path1:path2:...> */
	std::string  Subtitles::subPaths = "sub-paths";
	/** --sub-file-paths=<path-list> */
	std::string  Subtitles::subFilePaths = "sub-file-paths";
	/** --sub-visibility */
	std::string  Subtitles::subVisibility = "sub-visibility";
	/** --no-sub-visibility */
	std::string  Subtitles::noSubVisibility = "no-sub-visibility";
	/** --sub-clear-on-seek */
	std::string  Subtitles::subClearOnSeek = "sub-clear-on-seek";
	/** --testd::stringext-page=<1-999> */
	std::string  Subtitles::teletextPage = "teletext-page";
	/** --sub-font=<name> */
	std::string  Subtitles::subFont = "sub-font";
	/** --sub-font-size=<size> */
	std::string  Subtitles::subFontSize = "sub-font-size";
	/** --sub-back-color=<color> */
	std::string  Subtitles::subBackColor = "sub-back-color";
	/** --sub-blur=<0..20.0> */
	std::string  Subtitles::subBlur = "sub-blur";
	/** --sub-bold=<yes|no> */
	std::string  Subtitles::subBold = "sub-bold";
	/** --sub-italic=<yes|no> */
	std::string  Subtitles::subItalic = "sub-italic";
	/** --sub-border-color=<color> */
	std::string  Subtitles::subBorderColor = "sub-border-color";
	/** --sub-border-size=<size> */
	std::string  Subtitles::subBorderSize = "sub-border-size";
	/** --sub-color=<color> */
	std::string  Subtitles::subColor = "sub-color";
	/** --sub-margin-x=<size> */
	std::string  Subtitles::subMarginX = "sub-margin-x";
	/** --sub-margin-y=<size> */
	std::string  Subtitles::subMarginY = "sub-margin-y";
	/** --sub-align-x=<left|center|right> */
	std::string  Subtitles::subAlignX = "sub-align-x";
	/** --sub-align-y=<top|center|bottom> */
	std::string  Subtitles::subAlignY = "sub-align-y";
	/** --sub-justify=<auto|left|center|right> */
	std::string  Subtitles::subJustify = "sub-justify";
	/** --sub-ass-justify=<yes|no> */
	std::string  Subtitles::subAssJustify = "sub-ass-justify";
	/** --sub-shadow-color=<color> */
	std::string  Subtitles::subShadowColor = "sub-shadow-color";
	/** --sub-shadow-offset=<size> */
	std::string  Subtitles::subShadowOffset = "sub-shadow-offset";
	/** --sub-spacing=<size> */
	std::string  Subtitles::subSpacing = "sub-spacing";
	/** --sub-filter-sdh=<yes|no> */
	std::string  Subtitles::subFilterSdh = "sub-filter-sdh";
	/** --sub-filter-sdh-harder=<yes|no> */
	std::string  Subtitles::subFilterSdhHarder = "sub-filter-sdh-harder";
	/** --sub-create-cc-track=<yes|no> */
	std::string  Subtitles::subCreateCcTrack = "sub-create-cc-track";

	
	/** --title=<string> */
	std::string  Window::title = "title";
	/** --screen=<default|0-32> */
	std::string  Window::screen = "screen";
	/** --fullscreen */
	std::string  Window::fullscreen = "fullscreen";
	/** --fs */
	std::string  Window::fs = "fs";
	/** --fs-screen=<all|current|0-32> */
	std::string  Window::fsScreen = "fs-screen";
	/** --keep-open=<yes|no|always> */
	std::string  Window::keepOpen = "keep-open";
	/** --keep-open-pause=<yes|no> */
	std::string  Window::keepOpenPause = "keep-open-pause";
	/** --image-display-duration=<seconds|inf> */
	std::string  Window::imageDisplayDuration = "image-display-duration";
	/** --force-window=<yes|no|immediate> */
	std::string  Window::forceWindow = "force-window";
	/** --taskbar-progress */
	std::string  Window::taskbarProgress = "taskbar-progress";
	/** --no-taskbar-progress */
	std::string  Window::noTaskbarProgress = "no-taskbar-progress";
	/** --snap-window */
	std::string  Window::snapWindow = "snap-window";
	/** --ontop */
	std::string  Window::ontop = "ontop";
	/** --ontop-level=<window|system|level> */
	std::string  Window::ontopLevel = "ontop-level";
	/** --border */
	std::string  Window::border = "border";
	/** --no-border */
	std::string  Window::noBorder = "no-border";
	/** --fit-border */
	std::string  Window::fitBorder = "fit-border";
	/** --no-fit-border */
	std::string  Window::noFitBorder = "no-fit-border";
	/** --on-all-workspaces */
	std::string  Window::onAllWorkspaces = "on-all-workspaces";
	/** --geometry=<[W[xH]][+-x+-y]> */
	std::string  Window::geometry = "geometry";
	/** --autofit=<[W[xH]]> */
	std::string  Window::autofit = "autofit";
	/** --autofit-larger=<[W[xH]]> */
	std::string  Window::autofitLarger = "autofit-larger";
	/** --autofit-smaller=<[W[xH]]> */
	std::string  Window::autofitSmaller = "autofit-smaller";
	/** --window-scale=<factor> */
	std::string  Window::windowScale = "window-scale";
	/** --cursor-autohide=<number|no|always> */
	std::string  Window::cursorAutohide = "cursor-autohide";
	/** --cursor-autohide-fs-only */
	std::string  Window::cursorAutohideFsOnly = "cursor-autohide-fs-only";
	/** --no-fixed-vo */
	std::string  Window::noFixedVo = "no-fixed-vo";
	/** --fixed-vo */
	std::string  Window::fixedVo = "fixed-vo";
	/** --force-rgba-osd-rendering */
	std::string  Window::forceRgbaOsdRendering = "force-rgba-osd-rendering";
	/** --force-window-position */
	std::string  Window::forceWindowPosition = "force-window-position";
	/** --no-keepaspect */
	std::string  Window::noKeepaspect = "no-keepaspect";
	/** --keepaspect */
	std::string  Window::keepaspect = "keepaspect";
	/** --no-keepaspect-window */
	std::string  Window::noKeepaspectWindow = "no-keepaspect-window";
	/** --keepaspect-window */
	std::string  Window::keepaspectWindow = "keepaspect-window";
	/** --monitoraspect=<ratio> */
	std::string  Window::monitoraspect = "monitoraspect";
	/** --hidpi-window-scale */
	std::string  Window::hidpiWindowScale = "hidpi-window-scale";
	/** --no-hidpi-window-scale */
	std::string  Window::noHidpiWindowScale = "no-hidpi-window-scale";
	/** --native-fs */
	std::string  Window::nativeFs = "native-fs";
	/** --no-native-fs */
	std::string  Window::noNativeFs = "no-native-fs";
	/** --monitorpixelaspect=<ratio> */
	std::string  Window::monitorpixelaspect = "monitorpixelaspect";
	/** --stop-screensaver */
	std::string  Window::stopScreensaver = "stop-screensaver";
	/** --no-stop-screensaver */
	std::string  Window::noStopScreensaver = "no-stop-screensaver";
	/** --wid=<ID> */
	std::string  Window::wid = "wid";
	/** --no-window-dragging */
	std::string  Window::noWindowDragging = "no-window-dragging";
	/** --x11-name */
	std::string  Window::x11Name = "x11-name";
	/** --x11-netwm=<yes|no|auto> */
	std::string  Window::x11Netwm = "x11-netwm";
	/** --x11-bypass-compositor=<yes|no|fs-only|never> */
	std::string  Window::x11BypassCompositor = "x11-bypass-compositor";


	/** --cdrom-device=<path> */
	std::string  DiscDevices::cdromDevice = "cdrom-device";
	/** --dvd-device=<path> */
	std::string  DiscDevices::dvdDevice = "dvd-device";
	/** --bluray-device=<path> */
	std::string  DiscDevices::blurayDevice = "bluray-device";
	/** --cdda-speed=<value> */
	std::string  DiscDevices::cddaSpeed = "cdda-speed";
	/** --cdda-paranoia=<0-2> */
	std::string  DiscDevices::cddaParanoia = "cdda-paranoia";
	/** --cdda-sector-size=<value> */
	std::string  DiscDevices::cddaSectorSize = "cdda-sector-size";
	/** --cdda-overlap=<value> */
	std::string  DiscDevices::cddaOverlap = "cdda-overlap";
	/** --cdda-toc-bias */
	std::string  DiscDevices::cddaTocBias = "cdda-toc-bias";
	/** --cdda-toc-offset=<value> */
	std::string  DiscDevices::cddaTocOffset = "cdda-toc-offset";
	/** --cdda-skip=<yes|no> */
	std::string  DiscDevices::cddaSkip = "cdda-skip";
	/** --cdda-cdtext=<yes|no> */
	std::string  DiscDevices::cddaCdtext = "cdda-cdtext";
	/** --dvd-speed=<speed> */
	std::string  DiscDevices::dvdSpeed = "dvd-speed";
	/** --dvd-angle=<ID> */
	std::string  DiscDevices::dvdAngle = "dvd-angle";


	/** --brightness=<-100-100> */
	std::string Equalizer::brightness = "brightness";
	/** --contrast=<-100-100> */
	std::string Equalizer::contrast = "contrast";
	/** --saturation=<-100-100> */
	std::string Equalizer::saturation = "saturation";
	/** --gamma=<-100-100> */
	std::string Equalizer::gamma = "gamma";
	/** --hue=<-100-100> */
	std::string Equalizer::hue = "hue";

	
	/** --demuxer=<[+]name> */
	std::string Demuxer::demuxer = "demuxer";
	/** --demuxer-lavf-analyzeduration=<value> */
	std::string Demuxer::demuxerLavfAnalyzeduration = "demuxer-lavf-analyzeduration";
	/** --demuxer-lavf-probe-info=<yes|no|auto> */
	std::string Demuxer::demuxerLavfProbeInfo = "demuxer-lavf-probe-info";
	/** --demuxer-lavf-probescore=<1-100> */
	std::string Demuxer::demuxerLavfProbescore = "demuxer-lavf-probescore";
	/** --demuxer-lavf-allow-mimetype=<yes|no> */
	std::string Demuxer::demuxerLavfAllowMimetype = "demuxer-lavf-allow-mimetype";
	/** --demuxer-lavf-format=<name> */
	std::string Demuxer::demuxerLavfFormat = "demuxer-lavf-format";
	/** --demuxer-lavf-hacks=<yes|no> */
	std::string Demuxer::demuxerLavfHacks = "demuxer-lavf-hacks";
	/** --demuxer-lavf-genpts-mode=<no|lavf> */
	std::string Demuxer::demuxerLavfGenptsMode = "demuxer-lavf-genpts-mode";
	/** --demuxer-lavf-o=<key>=<value>[ */
	std::string Demuxer::demuxerLavfO = "demuxer-lavf-o";
	/** --demuxer-lavf-probesize=<value> */
	std::string Demuxer::demuxerLavfProbesize = "demuxer-lavf-probesize";
	/** --demuxer-lavf-buffersize=<value> */
	std::string Demuxer::demuxerLavfBuffersize = "demuxer-lavf-buffersize";
	/** --demuxer-mkv-subtitle-preroll=<yes|index|no> */
	std::string Demuxer::demuxerMkvSubtitlePreroll = "demuxer-mkv-subtitle-preroll";
	/** --mkv-subtitle-preroll */
	std::string Demuxer::mkvSubtitlePreroll = "mkv-subtitle-preroll";
	/** --demuxer-mkv-subtitle-preroll-secs=<value> */
	std::string Demuxer::demuxerMkvSubtitlePrerollSecs = "demuxer-mkv-subtitle-preroll-secs";
	/** --demuxer-mkv-subtitle-preroll-secs-index=<value> */
	std::string Demuxer::demuxerMkvSubtitlePrerollSecsIndex = "demuxer-mkv-subtitle-preroll-secs-index";
	/** --demuxer-mkv-probe-video-duration=<yes|no|full> */
	std::string Demuxer::demuxerMkvProbeVideoDuration = "demuxer-mkv-probe-video-duration";
	/** --demuxer-rawaudio-channels=<value> */
	std::string Demuxer::demuxerRawaudioChannels = "demuxer-rawaudio-channels";
	/** --demuxer-rawaudio-format=<value> */
	std::string Demuxer::demuxerRawaudioFormat = "demuxer-rawaudio-format";
	/** --demuxer-rawaudio-rate=<value> */
	std::string Demuxer::demuxerRawaudioRate = "demuxer-rawaudio-rate";
	/** --demuxer-rawvideo-fps=<value> */
	std::string Demuxer::demuxerRawvideoFps = "demuxer-rawvideo-fps";
	/** --demuxer-rawvideo-w=<value> */
	std::string Demuxer::demuxerRawvideoW = "demuxer-rawvideo-w";
	/** --demuxer-rawvideo-h=<value> */
	std::string Demuxer::demuxerRawvideoH = "demuxer-rawvideo-h";
	/** --demuxer-rawvideo-format=<value> */
	std::string Demuxer::demuxerRawvideoFormat = "demuxer-rawvideo-format";
	/** --demuxer-rawvideo-mp-format=<value> */
	std::string Demuxer::demuxerRawvideoMpFormat = "demuxer-rawvideo-mp-format";
	/** --demuxer-rawvideo-codec=<value> */
	std::string Demuxer::demuxerRawvideoCodec = "demuxer-rawvideo-codec";
	/** --demuxer-rawvideo-size=<value> */
	std::string Demuxer::demuxerRawvideoSize = "demuxer-rawvideo-size";
	/** --demuxer-max-bytes=<bytes> */
	std::string Demuxer::demuxerMaxBytes = "demuxer-max-bytes";
	/** --demuxer-max-back-bytes=<value> */
	std::string Demuxer::demuxerMaxBackBytes = "demuxer-max-back-bytes";
	/** --demuxer-seekable-cache=<yes|no|auto> */
	std::string Demuxer::demuxerSeekableCache = "demuxer-seekable-cache";
	/** --demuxer-thread=<yes|no> */
	std::string Demuxer::demuxerThread = "demuxer-thread";
	/** --demuxer-readahead-secs=<seconds> */
	std::string Demuxer::demuxerReadaheadSecs = "demuxer-readahead-secs";
	/** --prefetch-playlist=<yes|no> */
	std::string Demuxer::prefetchPlaylist = "prefetch-playlist";
	/** --force-seekable=<yes|no> */
	std::string Demuxer::forceSeekable = "force-seekable";


	/** --native-keyrepeat */
	static std::string nativeKeyrepeat = "native-keyrepeat";
	/** --input-ar-delay */
	static std::string inputArDelay = "input-ar-delay";
	/** --input-ar-rate */
	static std::string inputArRate = "input-ar-rate";
	/** --input-conf=<filename> */
	static std::string inputConf = "input-conf";
	/** --no-input-default-bindings */
	static std::string noInputDefaultBindings = "no-input-default-bindings";
	/** --input-cmdlist */
	static std::string inputCmdlist = "input-cmdlist";
	/** --input-doubleclick-time=<milliseconds> */
	static std::string inputDoubleclickTime = "input-doubleclick-time";
	/** --input-keylist */
	static std::string inputKeylist = "input-keylist";
	/** --input-key-fifo-size=<2-65000> */
	static std::string inputKeyFifoSize = "input-key-fifo-size";
	/** --input-test */
	static std::string inputTest = "input-test";
	/** --input-file=<filename> */
	static std::string inputFile = "input-file";
	/** --input-terminal */
	static std::string inputTerminal = "input-terminal";
	/** --no-input-terminal */
	static std::string noInputTerminal = "no-input-terminal";
	/** --input-ipc-server=<filename> */
	static std::string inputIpcServer = "input-ipc-server";
	/** --input-appleremote=<yes|no> */
	static std::string inputAppleremote = "input-appleremote";
	/** --input-cursor */
	static std::string inputCursor = "input-cursor";
	/** --no-input-cursor */
	static std::string noInputCursor = "no-input-cursor";
	/** --input-media-keys=<yes|no> */
	static std::string inputMediaKeys = "input-media-keys";
	/** --input-right-alt-gr */
	static std::string inputRightAltGr = "input-right-alt-gr";
	/** --no-input-right-alt-gr */
	static std::string noInputRightAltGr = "no-input-right-alt-gr";
	/** --input-vo-keyboard=<yes|no> */
	static std::string inputVoKeyboard = "input-vo-keyboard";


	/** --osc */
	std::string OSD::osc = "osc";
	/** --no-osc */
	std::string OSD::noOsc = "no-osc";
	/** --no-osd-bar */
	std::string OSD::noOsdBar = "no-osd-bar";
	/** --osd-bar */
	std::string OSD::osdBar = "osd-bar";
	/** --osd-duration=<time> */
	std::string OSD::osdDuration = "osd-duration";
	/** --osd-font=<name> */
	std::string OSD::osdFont = "osd-font";
	/** --osd-font-size=<size> */
	std::string OSD::osdFontSize = "osd-font-size";
	/** --osd-msg1=<string> */
	std::string OSD::osdMsg1 = "osd-msg1";
	/** --osd-msg2=<string> */
	std::string OSD::osdMsg2 = "osd-msg2";
	/** --osd-msg3=<string> */
	std::string OSD::osdMsg3 = "osd-msg3";
	/** --osd-status-msg=<string> */
	std::string OSD::osdStatusMsg = "osd-status-msg";
	/** --osd-playing-msg=<string> */
	std::string OSD::osdPlayingMsg = "osd-playing-msg";
	/** --osd-bar-align-x=<-1-1> */
	std::string OSD::osdBarAlignX = "osd-bar-align-x";
	/** --osd-bar-align-y=<-1-1> */
	std::string OSD::osdBarAlignY = "osd-bar-align-y";
	/** --osd-bar-w=<1-100> */
	std::string OSD::osdBarW = "osd-bar-w";
	/** --osd-bar-h=<0.1-50> */
	std::string OSD::osdBarH = "osd-bar-h";
	/** --osd-back-color=<color> */
	std::string OSD::osdBackColor = "osd-back-color";
	/** --osd-blur=<0..20.0> */
	std::string OSD::osdBlur = "osd-blur";
	/** --osd-bold=<yes|no> */
	std::string OSD::osdBold = "osd-bold";
	/** --osd-italic=<yes|no> */
	std::string OSD::osdItalic = "osd-italic";
	/** --osd-border-color=<color> */
	std::string OSD::osdBorderColor = "osd-border-color";
	/** --osd-border-size=<size> */
	std::string OSD::osdBorderSize = "osd-border-size";
	/** --osd-color=<color> */
	std::string OSD::osdColor = "osd-color";
	/** --osd-fractions */
	std::string OSD::osdFractions = "osd-fractions";
	/** --osd-level=<0-3> */
	std::string OSD::osdLevel = "osd-level";
	/** --osd-margin-x=<size> */
	std::string OSD::osdMarginX = "osd-margin-x";
	/** --osd-margin-y=<size> */
	std::string OSD::osdMarginY = "osd-margin-y";
	/** --osd-align-x=<left|center|right> */
	std::string OSD::osdAlignX = "osd-align-x";
	/** --osd-align-y=<top|center|bottom> */
	std::string OSD::osdAlignY = "osd-align-y";
	/** --osd-scale=<factor> */
	std::string OSD::osdScale = "osd-scale";
	/** --osd-scale-by-window=<yes|no> */
	std::string OSD::osdScaleByWindow = "osd-scale-by-window";
	/** --osd-shadow-color=<color> */
	std::string OSD::osdShadowColor = "osd-shadow-color";
	/** --osd-shadow-offset=<size> */
	std::string OSD::osdShadowOffset = "osd-shadow-offset";
	/** --osd-spacing=<size> */
	std::string OSD::osdSpacing = "osd-spacing";
	/** --video-osd=<yes|no> */
	std::string OSD::videoOsd = "video-osd";


	/** --screenshot-format=<type> */
	std::string Screenshot::screenshotFormat = "screenshot-format";
	/** --screenshot-tag-colorspace=<yes|no> */
	std::string Screenshot::screenshotTagColorspace = "screenshot-tag-colorspace";
	/** --screenshot-high-bit-depth=<yes|no> */
	std::string Screenshot::screenshotHighBitDepth = "screenshot-high-bit-depth";
	/** --screenshot-template=<template> */
	std::string Screenshot::screenshotTemplate = "screenshot-template";
	/** --screenshot-directory=<path> */
	std::string Screenshot::screenshotDirectory = "screenshot-directory";
	/** --screenshot-jpeg-quality=<0-100> */
	std::string Screenshot::screenshotJpegQuality = "screenshot-jpeg-quality";
	/** --screenshot-jpeg-source-chroma=<yes|no> */
	std::string Screenshot::screenshotJpegSourceChroma = "screenshot-jpeg-source-chroma";
	/** --screenshot-png-compression=<0-9> */
	std::string Screenshot::screenshotPngCompression = "screenshot-png-compression";
	/** --screenshot-png-filter=<0-5> */
	std::string Screenshot::screenshotPngFilter = "screenshot-png-filter";


	/** --sws-scaler=<name> */
	std::string SoftwareScaler::swsScaler = "sws-scaler";
	/** --sws-lgb=<0-100> */
	std::string SoftwareScaler::swsLgb = "sws-lgb";
	/** --sws-cgb=<0-100> */
	std::string SoftwareScaler::swsCgb = "sws-cgb";
	/** --sws-ls=<-100-100> */
	std::string SoftwareScaler::swsLs = "sws-ls";
	/** --sws-cs=<-100-100> */
	std::string SoftwareScaler::swsCs = "sws-cs";
	/** --sws-chs=<h> */
	std::string SoftwareScaler::swsChs = "sws-chs";
	/** --sws-cvs=<v> */
	std::string SoftwareScaler::swsCvs = "sws-cvs";


	/** --quiet */
	std::string Terminal::quiet = "quiet";
	/** --really-quiet */
	std::string Terminal::reallyQuiet = "really-quiet";
	/** --no-terminal */
	std::string Terminal::noTerminal = "no-terminal";
	/** --terminal */
	std::string Terminal::terminal = "terminal";
	/** --no-msg-color */
	std::string Terminal::noMsgColor = "no-msg-color";
	/** --msg-level=<module1=level1 */
	std::string Terminal::msgLevel = "msg-level";
	/** --term-osd=<auto|no|force> */
	std::string Terminal::termOsd = "term-osd";
	/** --term-osd-bar */
	std::string Terminal::termOsdBar = "term-osd-bar";
	/** --no-term-osd-bar */
	std::string Terminal::noTermOsdBar = "no-term-osd-bar";
	/** --term-osd-bar-chars=<string> */
	std::string Terminal::termOsdBarChars = "term-osd-bar-chars";
	/** --term-playing-msg=<string> */
	std::string Terminal::termPlayingMsg = "term-playing-msg";
	/** --term-status-msg=<string> */
	std::string Terminal::termStatusMsg = "term-status-msg";
	/** --msg-module */
	std::string Terminal::msgModule = "msg-module";
	/** --msg-time */
	std::string Terminal::msgTime = "msg-time";


	/** --cache=<kBytes|yes|no|auto> */
	std::string Cache::cache = "cache";
	/** --cache-default=<kBytes|no> */
	std::string Cache::cacheDefault = "cache-default";
	/** --cache-initial=<kBytes> */
	std::string Cache::cacheInitial = "cache-initial";
	/** --cache-seek-min=<kBytes> */
	std::string Cache::cacheSeekMin = "cache-seek-min";
	/** --cache-backbuffer=<kBytes> */
	std::string Cache::cacheBackbuffer = "cache-backbuffer";
	/** --cache-file=<TMP|path> */
	std::string Cache::cacheFile = "cache-file";
	/** --cache-file-size=<kBytes> */
	std::string Cache::cacheFileSize = "cache-file-size";
	/** --no-cache */
	std::string Cache::noCache = "no-cache";
	/** --cache-secs=<seconds> */
	std::string Cache::cacheSecs = "cache-secs";
	/** --cache-pause */
	std::string Cache::cachePause = "cache-pause";
	/** --no-cache-pause */
	std::string Cache::noCachePause = "no-cache-pause";


	/** --user-agent=<string> */
	std::string Network::userAgent = "user-agent";
	/** --cookies */
	std::string Network::cookies = "cookies";
	/** --no-cookies */
	std::string Network::noCookies = "no-cookies";
	/** --cookies-file=<filename> */
	std::string Network::cookiesFile = "cookies-file";
	/** --http-header-fields=<field1 */
	std::string Network::httpHeaderFields = "http-header-fields";
	/** --tls-ca-file=<filename> */
	std::string Network::tlsCaFile = "tls-ca-file";
	/** --tls-verify */
	std::string Network::tlsVerify = "tls-verify";
	/** --tls-cert-file */
	std::string Network::tlsCertFile = "tls-cert-file";
	/** --tls-key-file */
	std::string Network::tlsKeyFile = "tls-key-file";
	/** --referrer=<string> */
	std::string Network::referrer = "referrer";
	/** --network-timeout=<seconds> */
	std::string Network::networkTimeout = "network-timeout";
	/** --rtsp-transport=<lavf|udp|tcp|http> */
	std::string Network::rtspTransport = "rtsp-transport";
	/** --hls-bitrate=<no|min|max|<rate>> */
	std::string Network::hlsBitrate = "hls-bitrate";


	/** --dvbin-card=<1-4> */
	std::string DVB::dvbinCard = "dvbin-card";
	/** --dvbin-file=<filename> */
	std::string DVB::dvbinFile = "dvbin-file";
	/** --dvbin-timeout=<1-30> */
	std::string DVB::dvbinTimeout = "dvbin-timeout";
	/** --dvbin-full-transponder=<yes|no> */
	std::string DVB::dvbinFullTransponder = "dvbin-full-transponder";


	/** --alsa-device=<device> */
	std::string ALSAAudioOutputOptions::alsaDevice = "alsa-device";
	/** --alsa-resample=yes */
	std::string ALSAAudioOutputOptions::alsaResample = "alsa-resample";
	/** --alsa-mixer-device=<device> */
	std::string ALSAAudioOutputOptions::alsaMixerDevice = "alsa-mixer-device";
	/** --alsa-mixer-name=<name> */
	std::string ALSAAudioOutputOptions::alsaMixerName = "alsa-mixer-name";
	/** --alsa-mixer-index=<number> */
	std::string ALSAAudioOutputOptions::alsaMixerIndex = "alsa-mixer-index";
	/** --alsa-non-interleaved */
	std::string ALSAAudioOutputOptions::alsaNonInterleaved = "alsa-non-interleaved";
	/** --alsa-ignore-chmap */
	std::string ALSAAudioOutputOptions::alsaIgnoreChmap = "alsa-ignore-chmap";

	/** --scale=<filter> */
	std::string GPURendererOptions::scale = "scale";
	/** --cscale=<filter> */
	std::string GPURendererOptions::cscale = "cscale";
	/** --dscale=<filter> */
	std::string GPURendererOptions::dscale = "dscale";
	/** --tscale=<filter> */
	std::string GPURendererOptions::tscale = "tscale";
	/** --scale-param1=<value> */
	std::string GPURendererOptions::scaleParam1 = "scale-param1";
	/** --scale-param2=<value> */
	std::string GPURendererOptions::scaleParam2 = "scale-param2";
	/** --cscale-param1=<value> */
	std::string GPURendererOptions::cscaleParam1 = "cscale-param1";
	/** --cscale-param2=<value> */
	std::string GPURendererOptions::cscaleParam2 = "cscale-param2";
	/** --dscale-param1=<value> */
	std::string GPURendererOptions::dscaleParam1 = "dscale-param1";
	/** --dscale-param2=<value> */
	std::string GPURendererOptions::dscaleParam2 = "dscale-param2";
	/** --tscale-param1=<value> */
	std::string GPURendererOptions::tscaleParam1 = "tscale-param1";
	/** --tscale-param2=<value> */
	std::string GPURendererOptions::tscaleParam2 = "tscale-param2";
	/** --scale-blur=<value> */
	std::string GPURendererOptions::scaleBlur = "scale-blur";
	/** --scale-wblur=<value> */
	std::string GPURendererOptions::scaleWblur = "scale-wblur";
	/** --cscale-blur=<value> */
	std::string GPURendererOptions::cscaleBlur = "cscale-blur";
	/** --cscale-wblur=<value> */
	std::string GPURendererOptions::cscaleWblur = "cscale-wblur";
	/** --dscale-blur=<value> */
	std::string GPURendererOptions::dscaleBlur = "dscale-blur";
	/** --dscale-wblur=<value> */
	std::string GPURendererOptions::dscaleWblur = "dscale-wblur";
	/** --tscale-blur=<value> */
	std::string GPURendererOptions::tscaleBlur = "tscale-blur";
	/** --tscale-wblur=<value> */
	std::string GPURendererOptions::tscaleWblur = "tscale-wblur";
	/** --scale-clamp=<0.0-1.0> */
	std::string GPURendererOptions::scaleClamp = "scale-clamp";
	/** --cscale-clamp */
	std::string GPURendererOptions::cscaleClamp = "cscale-clamp";
	/** --dscale-clamp */
	std::string GPURendererOptions::dscaleClamp = "dscale-clamp";
	/** --tscale-clamp */
	std::string GPURendererOptions::tscaleClamp = "tscale-clamp";
	/** --scale-cutoff=<value> */
	std::string GPURendererOptions::scaleCutoff = "scale-cutoff";
	/** --cscale-cutoff=<value> */
	std::string GPURendererOptions::cscaleCutoff = "cscale-cutoff";
	/** --dscale-cutoff=<value> */
	std::string GPURendererOptions::dscaleCutoff = "dscale-cutoff";
	/** --scale-taper=<value> */
	std::string GPURendererOptions::scaleTaper = "scale-taper";
	/** --scale-wtaper=<value> */
	std::string GPURendererOptions::scaleWtaper = "scale-wtaper";
	/** --dscale-taper=<value> */
	std::string GPURendererOptions::dscaleTaper = "dscale-taper";
	/** --dscale-wtaper=<value> */
	std::string GPURendererOptions::dscaleWtaper = "dscale-wtaper";
	/** --cscale-taper=<value> */
	std::string GPURendererOptions::cscaleTaper = "cscale-taper";
	/** --cscale-wtaper=<value> */
	std::string GPURendererOptions::cscaleWtaper = "cscale-wtaper";
	/** --tscale-taper=<value> */
	std::string GPURendererOptions::tscaleTaper = "tscale-taper";
	/** --tscale-wtaper=<value> */
	std::string GPURendererOptions::tscaleWtaper = "tscale-wtaper";
	/** --scale-radius=<value> */
	std::string GPURendererOptions::scaleRadius = "scale-radius";
	/** --cscale-radius=<value> */
	std::string GPURendererOptions::cscaleRadius = "cscale-radius";
	/** --dscale-radius=<value> */
	std::string GPURendererOptions::dscaleRadius = "dscale-radius";
	/** --tscale-radius=<value> */
	std::string GPURendererOptions::tscaleRadius = "tscale-radius";
	/** --scale-antiring=<value> */
	std::string GPURendererOptions::scaleAntiring = "scale-antiring";
	/** --cscale-antiring=<value> */
	std::string GPURendererOptions::cscaleAntiring = "cscale-antiring";
	/** --dscale-antiring=<value> */
	std::string GPURendererOptions::dscaleAntiring = "dscale-antiring";
	/** --tscale-antiring=<value> */
	std::string GPURendererOptions::tscaleAntiring = "tscale-antiring";
	/** --scale-window=<window> */
	std::string GPURendererOptions::scaleWindow = "scale-window";
	/** --cscale-window=<window> */
	std::string GPURendererOptions::cscaleWindow = "cscale-window";
	/** --dscale-window=<window> */
	std::string GPURendererOptions::dscaleWindow = "dscale-window";
	/** --tscale-window=<window> */
	std::string GPURendererOptions::tscaleWindow = "tscale-window";
	/** --scale-wparam=<window> */
	std::string GPURendererOptions::scaleWparam = "scale-wparam";
	/** --cscale-wparam=<window> */
	std::string GPURendererOptions::cscaleWparam = "cscale-wparam";
	/** --tscale-wparam=<window> */
	std::string GPURendererOptions::tscaleWparam = "tscale-wparam";
	/** --scaler-lut-size=<4..10> */
	std::string GPURendererOptions::scalerLutSize = "scaler-lut-size";
	/** --scaler-resizes-only */
	std::string GPURendererOptions::scalerResizesOnly = "scaler-resizes-only";
	/** --linear-scaling */
	std::string GPURendererOptions::linearScaling = "linear-scaling";
	/** --correct-downscaling */
	std::string GPURendererOptions::correctDownscaling = "correct-downscaling";
	/** --interpolation */
	std::string GPURendererOptions::interpolation = "interpolation";
	/** --interpolation-threshold=<0..1 */
	std::string GPURendererOptions::interpolationThreshold = "interpolation-threshold";
	/** --opengl-pbo */
	std::string GPURendererOptions::openglPbo = "opengl-pbo";
	/** --dither-depth=<N|no|auto> */
	std::string GPURendererOptions::ditherDepth = "dither-depth";
	/** --dither-size-fruit=<2-8> */
	std::string GPURendererOptions::ditherSizeFruit = "dither-size-fruit";
	/** --dither=<fruit|ordered|no> */
	std::string GPURendererOptions::dither = "dither";
	/** --temporal-dither */
	std::string GPURendererOptions::temporalDither = "temporal-dither";
	/** --temporal-dither-period=<1-128> */
	std::string GPURendererOptions::temporalDitherPeriod = "temporal-dither-period";
	/** --gpu-debug */
	std::string GPURendererOptions::gpuDebug = "gpu-debug";
	/** --opengl-swapinterval=<n> */
	std::string GPURendererOptions::openglSwapinterval = "opengl-swapinterval";
	/** --vulkan-swap-mode=<mode> */
	std::string GPURendererOptions::vulkanSwapMode = "vulkan-swap-mode";
	/** --vulkan-queue-count=<1..8> */
	std::string GPURendererOptions::vulkanQueueCount = "vulkan-queue-count";
	/** --d3d11-warp=<yes|no|auto> */
	std::string GPURendererOptions::d3d11Warp = "d3d11-warp";
	/** --d3d11-feature-level=<12_1|12_0|11_1|11_0|10_1|10_0|9_3|9_2|9_1> */
	std::string GPURendererOptions::d3d11FeatureLevel = "d3d11-feature-level";
	/** --d3d11-flip=<yes|no> */
	std::string GPURendererOptions::d3d11Flip = "d3d11-flip";
	/** --d3d11-sync-interval=<0..4> */
	std::string GPURendererOptions::d3d11SyncInterval = "d3d11-sync-interval";
	/** --d3d11va-zero-copy=<yes|no> */
	std::string GPURendererOptions::d3d11vaZeroCopy = "d3d11va-zero-copy";
	/** --spirv-compiler=<compiler> */
	std::string GPURendererOptions::spirvCompiler = "spirv-compiler";
	/** --glsl-shaders=<file-list> */
	std::string GPURendererOptions::glslShaders = "glsl-shaders";
	/** --glsl-shader=<file> */
	std::string GPURendererOptions::glslShader = "glsl-shader";
	/** --deband */
	std::string GPURendererOptions::deband = "deband";
	/** --deband-iterations=<1..16> */
	std::string GPURendererOptions::debandIterations = "deband-iterations";
	/** --deband-threshold=<0..4096> */
	std::string GPURendererOptions::debandThreshold = "deband-threshold";
	/** --deband-range=<1..64> */
	std::string GPURendererOptions::debandRange = "deband-range";
	/** --deband-grain=<0..4096> */
	std::string GPURendererOptions::debandGrain = "deband-grain";
	/** --sigmoid-upscaling */
	std::string GPURendererOptions::sigmoidUpscaling = "sigmoid-upscaling";
	/** --sigmoid-center */
	std::string GPURendererOptions::sigmoidCenter = "sigmoid-center";
	/** --sigmoid-slope */
	std::string GPURendererOptions::sigmoidSlope = "sigmoid-slope";
	/** --sharpen=<value> */
	std::string GPURendererOptions::sharpen = "sharpen";
	/** --opengl-glfinish */
	std::string GPURendererOptions::openglGlfinish = "opengl-glfinish";
	/** --opengl-waitvsync */
	std::string GPURendererOptions::openglWaitvsync = "opengl-waitvsync";
	/** --opengl-dwmflush=<no|windowed|yes|auto> */
	std::string GPURendererOptions::openglDwmflush = "opengl-dwmflush";
	/** --angle-d3d11-feature-level=<11_0|10_1|10_0|9_3> */
	std::string GPURendererOptions::angleD3d11FeatureLevel = "angle-d3d11-feature-level";
	/** --angle-d3d11-warp=<yes|no|auto> */
	std::string GPURendererOptions::angleD3d11Warp = "angle-d3d11-warp";
	/** --angle-egl-windowing=<yes|no|auto> */
	std::string GPURendererOptions::angleEglWindowing = "angle-egl-windowing";
	/** --angle-flip=<yes|no> */
	std::string GPURendererOptions::angleFlip = "angle-flip";
	/** --angle-renderer=<d3d9|d3d11|auto> */;
	std::string GPURendererOptions::angleRenderer = "angle-renderer";
	/** --cocoa-force-dedicated-gpu=<yes|no> */
	std::string GPURendererOptions::cocoaForceDedicatedGpu = "cocoa-force-dedicated-gpu";
	/** --swapchain-depth=<N> */
	std::string GPURendererOptions::swapchainDepth = "swapchain-depth";
	/** --gpu-sw */
	std::string GPURendererOptions::gpuSw = "gpu-sw";
	/** --gpu-context=<sys> */
	std::string GPURendererOptions::gpuContext = "gpu-context";
	/** --gpu-api=<type> */
	std::string GPURendererOptions::gpuApi = "gpu-api";
	/** --opengl-es=<mode> */
	std::string GPURendererOptions::openglEs = "opengl-es";
	/** --opengl-restrict=<version> */
	std::string GPURendererOptions::openglRestrict = "opengl-restrict";
	/** --fbo-format=<fmt> */
	std::string GPURendererOptions::fboFormat = "fbo-format";
	/** --gamma-factor=<0.1..2.0> */
	std::string GPURendererOptions::gammaFactor = "gamma-factor";
	/** --gamma-auto */
	std::string GPURendererOptions::gammaAuto = "gamma-auto";
	/** --target-prim=<value> */
	std::string GPURendererOptions::targetPrim = "target-prim";
	/** --target-trc=<value> */
	std::string GPURendererOptions::targetTrc = "target-trc";
	/** --tone-mapping=<value> */
	std::string GPURendererOptions::toneMapping = "tone-mapping";
	/** --tone-mapping-param=<value> */
	std::string GPURendererOptions::toneMappingParam = "tone-mapping-param";
	/** --hdr-compute-peak */
	std::string GPURendererOptions::hdrComputePeak = "hdr-compute-peak";
	/** --tone-mapping-desaturate=<value> */
	std::string GPURendererOptions::toneMappingDesaturate = "tone-mapping-desaturate";
	/** --gamut-warning */
	std::string GPURendererOptions::gamutWarning = "gamut-warning";
	/** --use-embedded-icc-profile */
	std::string GPURendererOptions::useEmbeddedIccProfile = "use-embedded-icc-profile";
	/** --icc-profile=<file> */
	std::string GPURendererOptions::iccProfile = "icc-profile";
	/** --icc-profile-auto */
	std::string GPURendererOptions::iccProfileAuto = "icc-profile-auto";
	/** --icc-cache-dir=<dirname> */
	std::string GPURendererOptions::iccCacheDir = "icc-cache-dir";
	/** --icc-intent=<value> */
	std::string GPURendererOptions::iccIntent = "icc-intent";
	/** --icc-3dlut-size=<r>x<g>x<b> */
	std::string GPURendererOptions::icc3dlutSize = "icc-3dlut-size";
	/** --icc-contrast=<0-100000> */
	std::string GPURendererOptions::iccContrast = "icc-contrast";
	/** --blend-subtitles=<yes|video|no> */
	std::string GPURendererOptions::blendSubtitles = "blend-subtitles";
	/** --alpha=<blend-tiles|blend|yes|no> */
	std::string GPURendererOptions::alpha = "alpha";
	/** --opengl-rectangle-textures */
	std::string GPURendererOptions::openglRectangleTextures = "opengl-rectangle-textures";
	/** --background=<color> */
	std::string GPURendererOptions::background = "background";
	/** --gpu-tex-pad-x */
	std::string GPURendererOptions::gpuTexPadX = "gpu-tex-pad-x";
	/** --gpu-tex-pad-y */
	std::string GPURendererOptions::gpuTexPadY = "gpu-tex-pad-y";
	/** --opengl-early-flush=<yes|no|auto> */
	std::string GPURendererOptions::openglEarlyFlush = "opengl-early-flush";
	/** --gpu-dumb-mode=<yes|no|auto> */
	std::string GPURendererOptions::gpuDumbMode = "gpu-dumb-mode";
	/** --gpu-shader-cache-dir=<dirname> */
	std::string GPURendererOptions::gpuShaderCacheDir = "gpu-shader-cache-dir";
	/** --cuda-decode-device=<auto|0..> */
	std::string GPURendererOptions::cudaDecodeDevice = "cuda-decode-device";


	/** --display-tags=tag1 */
	std::string Miscellaneous::displayTags = "display-tags";
	/** --mc=<seconds/frame> */
	std::string Miscellaneous::mc = "mc";
	/** --autosync=<factor> */
	std::string Miscellaneous::autosync = "autosync";
	/** --video-sync=<audio|...> */
	std::string Miscellaneous::videoSync = "video-sync";
	/** --video-sync-max-video-change=<value> */
	std::string Miscellaneous::videoSyncMaxVideoChange = "video-sync-max-video-change";
	/** --video-sync-max-audio-change=<value> */
	std::string Miscellaneous::videoSyncMaxAudioChange = "video-sync-max-audio-change";
	/** --video-sync-adrop-size=<value> */
	std::string Miscellaneous::videoSyncAdropSize = "video-sync-adrop-size";
	/** --mf-fps=<value> */
	std::string Miscellaneous::mfFps = "mf-fps";
	/** --mf-type=<value> */
	std::string Miscellaneous::mfType = "mf-type";
	/** --stream-dump=<destination-filename> */
	std::string Miscellaneous::streamDump = "stream-dump";
	/** --stream-lavf-o=opt1=value1 */
	std::string Miscellaneous::streamLavfO = "stream-lavf-o";
	/** --vo-mmcss-profile=<name> */
	std::string Miscellaneous::voMmcssProfile = "vo-mmcss-profile";
	/** --priority=<prio> */
	std::string Miscellaneous::priority = "priority";
	/** --force-media-title=<string> */
	std::string Miscellaneous::forceMediaTitle = "force-media-title";
	/** --external-files=<file-list> */
	std::string Miscellaneous::externalFiles = "external-files";
	/** --external-file=<file> */
	std::string Miscellaneous::externalFile = "external-file";
	/** --autoload-files=<yes|no> */
	std::string Miscellaneous::autoloadFiles = "autoload-files";
	/** --record-file=<file> */
	std::string Miscellaneous::recordFile = "record-file";
	/** --lavfi-complex=<string> */
	std::string Miscellaneous::lavfiComplex = "lavfi-complex";

}




	/** audio-speed-correction */
	std::string MPVProperty::audioSpeedCorrection = "audio-speed-correction";
	/** video-speed-correction */
	std::string MPVProperty::videoSpeedCorrection = "video-speed-correction";
	/** display-sync-active */
	std::string MPVProperty::displaySyncActive = "display-sync-active";
	/** filename */
	std::string MPVProperty::filename = "filename";
	/** filename/no-ext */
	std::string MPVProperty::filenameNoExt = "filename/no-ext";
	/** file-size */
	std::string MPVProperty::fileSize = "file-size";
	/** estimated-frame-count */
	std::string MPVProperty::estimatedFrameCount = "estimated-frame-count";
	/** estimated-frame-number */
	std::string MPVProperty::estimatedFrameNumber = "estimated-frame-number";
	/** path */
	std::string MPVProperty::path = "path";
	/** media-title */
	std::string MPVProperty::mediaTitle = "media-title";
	/** file-format */
	std::string MPVProperty::fileFormat = "file-format";
	/** current-demuxer */
	std::string MPVProperty::currentDemuxer = "current-demuxer";
	/** stream-path */
	std::string MPVProperty::streamPath = "stream-path";
	/** stream-pos */
	std::string MPVProperty::streamPos = "stream-pos";
	/** stream-end */
	std::string MPVProperty::streamEnd = "stream-end";
	/** duration */
	std::string MPVProperty::duration = "duration";
	/** avsync */
	std::string MPVProperty::avsync = "avsync";
	/** total-avsync-change */
	std::string MPVProperty::totalAvsyncChange = "total-avsync-change";
	/** decoder-frame-drop-count */
	std::string MPVProperty::decoderFrameDropCount = "decoder-frame-drop-count";
	/** frame-drop-count */
	std::string MPVProperty::frameDropCount = "frame-drop-count";
	/** mistimed-frame-count */
	std::string MPVProperty::mistimedFrameCount = "mistimed-frame-count";
	/** vsync-ratio */
	std::string MPVProperty::vsyncRatio = "vsync-ratio";
	/** vo-delayed-frame-count */
	std::string MPVProperty::voDelayedFrameCount = "vo-delayed-frame-count";
	/** percent-pos */
	std::string MPVProperty::percentPos = "percent-pos";
	/** time-pos */
	std::string MPVProperty::timePos = "time-pos";
	/** time-start */
	std::string MPVProperty::timeStart = "time-start";
	/** time-remaining */
	std::string MPVProperty::timeRemaining = "time-remaining";
	/** audio-pts */
	std::string MPVProperty::audioPts = "audio-pts";
	/** playtime-remaining */
	std::string MPVProperty::playtimeRemaining = "playtime-remaining";
	/** playback-time */
	std::string MPVProperty::playbackTime = "playback-time";
	/** chapter */
	std::string MPVProperty::chapter = "chapter";
	/** edition */
	std::string MPVProperty::edition = "edition";
	/** disc-titles */
	std::string MPVProperty::discTitles = "disc-titles";
	/** disc-titles/count */
	std::string MPVProperty::discTitlesCount = "disc-titles/count";
	/** disc-titles/id */
	std::string MPVProperty::discTitlesId = "disc-titles/id";
	/** disc-titles/length */
	std::string MPVProperty::discTitlesLength = "disc-titles/length";
	/** disc-title-list */
	std::string MPVProperty::discTitleList = "disc-title-list";
	/** disc-title */
	std::string MPVProperty::discTitle = "disc-title";
	/** chapters */
	std::string MPVProperty::chapters = "chapters";
	/** editions */
	std::string MPVProperty::editions = "editions";
	/** edition-list */
	std::string MPVProperty::editionList = "edition-list";
	/** edition-list/count */
	std::string MPVProperty::editionListCount = "edition-list/count";
 
	/** angle */
	std::string MPVProperty::angle = "angle";
	/** metadata */
	std::string MPVProperty::metadata = "metadata";
	/** metadata/list/count */
	std::string MPVProperty::metadataListCount = "metadata/list/count";
 
	/** filtered-metadata */
	std::string MPVProperty::filteredMetadata = "filtered-metadata";
	/** chapter-metadata */
	std::string MPVProperty::chapterMetadata = "chapter-metadata";
	/** idle-active */
	std::string MPVProperty::idleActive = "idle-active";
	/** core-idle */
	std::string MPVProperty::coreIdle = "core-idle";
	/** cache */
	std::string MPVProperty::cache = "cache";
	/** cache-size */
	std::string MPVProperty::cacheSize = "cache-size";
	/** cache-free */
	std::string MPVProperty::cacheFree = "cache-free";
	/** cache-used */
	std::string MPVProperty::cacheUsed = "cache-used";
	/** cache-speed */
	std::string MPVProperty::cacheSpeed = "cache-speed";
	/** cache-idle */
	std::string MPVProperty::cacheIdle = "cache-idle";
	/** demuxer-cache-duration */
	std::string MPVProperty::demuxerCacheDuration = "demuxer-cache-duration";
	/** demuxer-cache-time */
	std::string MPVProperty::demuxerCacheTime = "demuxer-cache-time";
	/** demuxer-cache-idle */
	std::string MPVProperty::demuxerCacheIdle = "demuxer-cache-idle";
	/** demuxer-cache-state */
	std::string MPVProperty::demuxerCacheState = "demuxer-cache-state";
	/** eof */
	std::string MPVProperty::eof = "eof";
	/** underrun */
	std::string MPVProperty::underrun = "underrun";
	/** idle */
	std::string MPVProperty::idle = "idle";
	/** total-bytes */
	std::string MPVProperty::totalBytes = "total-bytes";
	/** fw-bytes */
	std::string MPVProperty::fwBytes = "fw-bytes";
	/** demuxer-via-network */
	std::string MPVProperty::demuxerViaNetwork = "demuxer-via-network";
	/** demuxer-start-time */
	std::string MPVProperty::demuxerStartTime = "demuxer-start-time";
	/** paused-for-cache */
	std::string MPVProperty::pausedForCache = "paused-for-cache";
	/** cache-buffering-state */
	std::string MPVProperty::cacheBufferingState = "cache-buffering-state";
	/** eof-reached */
	std::string MPVProperty::eofReached = "eof-reached";
	/** seeking */
	std::string MPVProperty::seeking = "seeking";
	/** mixer-active */
	std::string MPVProperty::mixerActive = "mixer-active";
	/** ao-volume */
	std::string MPVProperty::aoVolume = "ao-volume";
	/** ao-mute */
	std::string MPVProperty::aoMute = "ao-mute";
	/** audio-codec */
	std::string MPVProperty::audioCodec = "audio-codec";
	/** audio-codec-name */
	std::string MPVProperty::audioCodecName = "audio-codec-name";
	/** audio-params */
	std::string MPVProperty::audioParams = "audio-params";
	/** audio-params/format */
	std::string MPVProperty::audioParamsFormat = "audio-params/format";
	/** audio-params/samplerate */
	std::string MPVProperty::audioParamsSamplerate = "audio-params/samplerate";
	/** audio-params/channels */
	std::string MPVProperty::audioParamsChannels = "audio-params/channels";
	/** audio-params/hr-channels */
	std::string MPVProperty::audioParamsHrChannels = "audio-params/hr-channels";
	/** audio-params/channel-count */
	std::string MPVProperty::audioParamsChannelCount = "audio-params/channel-count";
	/** audio-out-params */
	std::string MPVProperty::audioOutParams = "audio-out-params";
	/** colormatrix */
	std::string MPVProperty::colormatrix = "colormatrix";
	/** colormatrix-input-range */
	std::string MPVProperty::colormatrixInputRange = "colormatrix-input-range";
	/** colormatrix-primaries */
	std::string MPVProperty::colormatrixPrimaries = "colormatrix-primaries";
	/** hwdec */
	std::string MPVProperty::hwdec = "hwdec";
	/** hwdec-current */
	std::string MPVProperty::hwdecCurrent = "hwdec-current";
	/** hwdec-interop */
	std::string MPVProperty::hwdecInterop = "hwdec-interop";
	/** video-format */
	std::string MPVProperty::videoFormat = "video-format";
	/** video-codec */
	std::string MPVProperty::videoCodec = "video-codec";
	/** width */
	std::string MPVProperty::width = "width";
	/** height */
	std::string MPVProperty::height = "height";
	/** video-params */
	std::string MPVProperty::videoParams = "video-params";
	/** video-params/pixelformat */
	std::string MPVProperty::videoParamsPixelformat = "video-params/pixelformat";
	/** video-params/average-bpp */
	std::string MPVProperty::videoParamsAverageBpp = "video-params/average-bpp";
	/** video-params/plane-depth */
	std::string MPVProperty::videoParamsPlaneDepth = "video-params/plane-depth";
	/** video-params/w */
	std::string MPVProperty::videoParamsW = "video-params/w";
	/** video-params/h */
	std::string MPVProperty::videoParamsH = "video-params/h";
	/** video-params/dw */
	std::string MPVProperty::videoParamsDw = "video-params/dw";
	/** video-params/dh */
	std::string MPVProperty::videoParamsDh = "video-params/dh";
	/** video-params/aspect */
	std::string MPVProperty::videoParamsAspect = "video-params/aspect";
	/** video-params/par */
	std::string MPVProperty::videoParamsPar = "video-params/par";
	/** video-params/colormatrix */
	std::string MPVProperty::videoParamsColormatrix = "video-params/colormatrix";
	/** video-params/colorlevels */
	std::string MPVProperty::videoParamsColorlevels = "video-params/colorlevels";
	/** video-params/primaries */
	std::string MPVProperty::videoParamsPrimaries = "video-params/primaries";
	/** video-params/gamma */
	std::string MPVProperty::videoParamsGamma = "video-params/gamma";
	/** video-params/sig-peak */
	std::string MPVProperty::videoParamsSigPeak = "video-params/sig-peak";
	/** video-params/light */
	std::string MPVProperty::videoParamsLight = "video-params/light";
	/** video-params/chroma-location */
	std::string MPVProperty::videoParamsChromaLocation = "video-params/chroma-location";
	/** video-params/rotate */
	std::string MPVProperty::videoParamsRotate = "video-params/rotate";
	/** video-params/stereo-in */
	std::string MPVProperty::videoParamsStereoIn = "video-params/stereo-in";
	/** dwidth */
	std::string MPVProperty::dwidth = "dwidth";
	/** dheight */
	std::string MPVProperty::dheight = "dheight";
	/** video-dec-params */
	std::string MPVProperty::videoDecParams = "video-dec-params";
	/** video-out-params */
	std::string MPVProperty::videoOutParams = "video-out-params";
	/** video-frame-info */
	std::string MPVProperty::videoFrameInfo = "video-frame-info";
	/** container-fps */
	std::string MPVProperty::containerFps = "container-fps";
	/** estimated-vf-fps */
	std::string MPVProperty::estimatedVfFps = "estimated-vf-fps";
	/** window-scale */
	std::string MPVProperty::windowScale = "window-scale";
	/** window-minimized */
	std::string MPVProperty::windowMinimized = "window-minimized";
	/** display-names */
	std::string MPVProperty::displayNames = "display-names";
	/** display-fps */
	std::string MPVProperty::displayFps = "display-fps";
	/** estimated-display-fps */
	std::string MPVProperty::estimatedDisplayFps = "estimated-display-fps";
	/** vsync-jitter */
	std::string MPVProperty::vsyncJitter = "vsync-jitter";
	/** video-aspect */
	std::string MPVProperty::videoAspect = "video-aspect";
	/** osd-width */
	std::string MPVProperty::osdWidth = "osd-width";
	/** osd-height */
	std::string MPVProperty::osdHeight = "osd-height";
	/** osd-par */
	std::string MPVProperty::osdPar = "osd-par";
	/** program */
	std::string MPVProperty::program = "program";
	/** dvb-channel */
	std::string MPVProperty::dvbChannel = "dvb-channel";
	/** dvb-channel-name */
	std::string MPVProperty::dvbChannelName = "dvb-channel-name";
	/** sub-text */
	std::string MPVProperty::subText = "sub-text";
	/** tv-brightness */
	std::string MPVProperty::tvBrightness = "tv-brightness";
	/** tv-contrast */
	std::string MPVProperty::tvContrast = "tv-contrast";
	/** tv-saturation */
	std::string MPVProperty::tvSaturation = "tv-saturation";
	/** tv-hue */
	std::string MPVProperty::tvHue = "tv-hue";
	/** playlist-pos */
	std::string MPVProperty::playlistPos = "playlist-pos";
	/** playlist-pos-1 */
	std::string MPVProperty::playlistPos1 = "playlist-pos-1";
	/** playlist-count */
	std::string MPVProperty::playlistCount = "playlist-count";
	/** playlist */
	std::string MPVProperty::playlist = "playlist";
	/** playlist/count */
	std::string MPVProperty::playlistCount2 = "playlist/count";
 
	/** track-list */
	std::string MPVProperty::trackList = "track-list";
	/** track-list/count */
	std::string MPVProperty::trackListCount = "track-list/count";

/** chapter-list */
	std::string MPVProperty::chapterList = "chapter-list";
	/** chapter-list/count */
	std::string MPVProperty::chapterListCount = "chapter-list/count";

	/** af */
	std::string MPVProperty::af = "af";
	/** vf */
	std::string MPVProperty::vf = "vf";
	/** seekable */
	std::string MPVProperty::seekable = "seekable";
	/** partially-seekable */
	std::string MPVProperty::partiallySeekable = "partially-seekable";
	/** playback-abort */
	std::string MPVProperty::playbackAbort = "playback-abort";
	/** cursor-autohide */
	std::string MPVProperty::cursorAutohide = "cursor-autohide";
	/** osd-sym-cc */
	std::string MPVProperty::osdSymCc = "osd-sym-cc";
	/** osd-ass-cc */
	std::string MPVProperty::osdAssCc = "osd-ass-cc";
	/** vo-configured */
	std::string MPVProperty::voConfigured = "vo-configured";
	/** vo-passes */
	std::string MPVProperty::voPasses = "vo-passes";
	/** vo-passes/TYPE/count */
	std::string MPVProperty::voPassesTYPECount = "vo-passes/TYPE/count";

	/** video-bitrate */
	std::string MPVProperty::videoBitrate = "video-bitrate";
	/** audio-bitrate */
	std::string MPVProperty::audioBitrate = "audio-bitrate";
	/** sub-bitrate */
	std::string MPVProperty::subBitrate = "sub-bitrate";
	/** packet-video-bitrate */
	std::string MPVProperty::packetVideoBitrate = "packet-video-bitrate";
	/** packet-audio-bitrate */
	std::string MPVProperty::packetAudioBitrate = "packet-audio-bitrate";
	/** packet-sub-bitrate */
	std::string MPVProperty::packetSubBitrate = "packet-sub-bitrate";
	/** audio-device-list */
	std::string MPVProperty::audioDeviceList = "audio-device-list";
	/** audio-device */
	std::string MPVProperty::audioDevice = "audio-device";
	/** current-vo */
	std::string MPVProperty::currentVo = "current-vo";
	/** current-ao */
	std::string MPVProperty::currentAo = "current-ao";
	/** working-directory */
	std::string MPVProperty::workingDirectory = "working-directory";
	/** protocol-list */
	std::string MPVProperty::protocolList = "protocol-list";
	/** decoder-list */
	std::string MPVProperty::decoderList = "decoder-list";
	/** family */
	std::string MPVProperty::family = "family";
	/** codec */
	std::string MPVProperty::codec = "codec";
	/** driver */
	std::string MPVProperty::driver = "driver";
	/** description */
	std::string MPVProperty::description = "description";
	/** encoder-list */
	std::string MPVProperty::encoderList = "encoder-list";
	/** mpv-version */
	std::string MPVProperty::mpvVersion = "mpv-version";
	/** mpv-configuration */
	std::string MPVProperty::mpvConfiguration = "mpv-configuration";
	/** ffmpeg-version */
	std::string MPVProperty::ffmpegVersion = "ffmpeg-version";

	/** property-list */
	std::string MPVProperty::propertyList = "property-list";
	/** profile-list */
	std::string MPVProperty::profileList = "profile-list";

	std::string MPVProperty::editionListNId(int n)
	{
		return "edition-list/" + std::to_string(n) + "/id";
	}

	std::string MPVProperty::editionListNDefault(int n)
	{
		return "edition-list/" + std::to_string(n) + "/default";
	}
	std::string MPVProperty::editionListNTitle(int n)
	{
		return "edition-list/" + std::to_string(n) + "/title";
	}
	std::string MPVProperty::metadataListNKey(int n)
	{
		return "metadata/list/" + std::to_string(n) + "/key";
	}
	std::string MPVProperty::metadataListNValue(int n)
	{
		return "metadata/list/" + std::to_string(n) + "/value";
	}
	std::string MPVProperty::playlistNFilename(int n)
	{
		return "playlist/" + std::to_string(n) + "/filename";
	}

	std::string MPVProperty::playlistNCurrent(int n)
	{
		return "playlist/" + std::to_string(n) + "/current";
	}

	std::string MPVProperty::playlistNPlaying(int n)
	{
		return "playlist/" + std::to_string(n) + "/playing";
	}

	std::string MPVProperty::playlistNTitle(int n)
	{
		return "playlist/" + std::to_string(n) + "/title";
	}

	std::string MPVProperty::trackListNId(int n)
	{
		return  "track-list/" + std::to_string(n) + "/id";
	}

	std::string MPVProperty::trackListNType(int n)
	{

		return  "track-list/"+std::to_string(n)+"/type";
	}

	std::string MPVProperty::trackListNSrcId(int n)
	{
		return "track-list/" + std::to_string(n) + "/src-id";
	}

	std::string MPVProperty::trackListNTitle(int n)
	{
		return "track-list/" + std::to_string(n) + "/title";
	}

	std::string MPVProperty::trackListNLang(int n)
	{
		return "track-list/" + std::to_string(n) + "/lang";
	}

	std::string MPVProperty::trackListNAlbumart(int n)
	{
		return "track-list/" + std::to_string(n) + "/albumart";
	}

	std::string MPVProperty::trackListNDefault(int n)
	{
		return "track-list/" + std::to_string(n) + "/default";
	}

	std::string MPVProperty::trackListNForced(int n)
	{
		return "track-list/" + std::to_string(n) + "/forced";
	}

	std::string MPVProperty::trackListNCodec(int n)
	{
		return "track-list/" + std::to_string(n) + "/codec";
	}

	std::string MPVProperty::trackListNExternal(int n)
	{
		return "track-list/" + std::to_string(n) + "/external";
	}
	std::string MPVProperty::trackListNExternalFilename(int n)
	{
		return "track-list/" + std::to_string(n) + "/external-filename";
	}
	std::string MPVProperty::trackListNSelected(int n)
	{
		return "track-list/" + std::to_string(n) + "/selected";
	}

	std::string MPVProperty::trackListNFfIndex(int n)
	{
		return "track-list/" + std::to_string(n) + "/ff-index";
	}

	std::string MPVProperty::trackListNDecoderDesc(int n)
	{
		return "track-list/" + std::to_string(n) + "/decoder-desc";
	}

	std::string MPVProperty::trackListNDemuxW(int n)
	{
		return "track-list/" + std::to_string(n) + "/demux-w";
	}
	std::string MPVProperty::trackListNDemuxH(int n)
	{
		return "track-list/" + std::to_string(n) + "/demux-h";
	}

	std::string MPVProperty::trackListNDemuxChannelCount(int n)
	{
		return "track-list/" + std::to_string(n) + "/demux-channel-count";
	}

	std::string MPVProperty::trackListNDemuxChannels(int n)
	{
		return "track-list/" + std::to_string(n) + "/demux-channels";
	}

	std::string MPVProperty::trackListNDemuxSamplerate(int n)
	{
		return "track-list/" + std::to_string(n) + "/demux-samplerate";
	}

	std::string MPVProperty::trackListNDemuxFps(int n)
	{
		return "track-list/" + std::to_string(n) + "/demux-fps";
	}

	std::string MPVProperty::trackListNAudioChannels(int n)
	{
		return "track-list/" + std::to_string(n) + "/audio-channels";
	}
	std::string MPVProperty::trackListNReplaygainTrackPeak(int n)
	{
		return "track-list/" + std::to_string(n) + "/replaygain-track-peak";
	}

	std::string MPVProperty::trackListNReplaygainTrackGain(int n)
	{
		return "track-list/" + std::to_string(n) + "/replaygain-track-gain";
	}

	std::string MPVProperty::trackListNReplaygainAlbumPeak(int n)
	{
		return "track-list/" + std::to_string(n) + "/replaygain-album-peak";
	}

	std::string MPVProperty::trackListNReplaygainAlbumGain(int n)
	{
		return "track-list/" + std::to_string(n) + "/replaygain-album-gain";
	}

	std::string MPVProperty::chapterListNTitle(int n)
	{
		return "chapter-list/" + std::to_string(n) + "/title";
	}

	std::string MPVProperty::chapterListNTime(int n)
	{
		return "chapter-list/" + std::to_string(n) + "/time";
	}

	std::string MPVProperty::voPassesTYPENDesc(int n)
	{
		return "vo-passes/TYPE/" + std::to_string(n) + "/desc";
	}

	std::string MPVProperty::voPassesTYPENLast(int n)
	{
		return "vo-passes/TYPE/" + std::to_string(n) + "/last";
	}

	std::string MPVProperty::voPassesTYPENAvg(int n)
	{
		return "vo-passes/TYPE/" + std::to_string(n) + "/avg";
	}

	std::string MPVProperty::voPassesTYPENPeak(int n)
	{
		return "vo-passes/TYPE/" + std::to_string(n) + "/peak";
	}

	std::string MPVProperty::voPassesTYPENCount(int n)
	{
		return "vo-passes/TYPE/" + std::to_string(n) + "/count";
	}

	std::string MPVProperty::voPassesTYPENSamplesM(int n)
	{
		return "vo-passes/TYPE/" + std::to_string(n) + "/samples/M";
	}

	std::string MPVProperty::options(std::string name)
	{
		return "options/" + name+ "";
	}

	std::string MPVProperty::fileLocalOptions(std::string name)
	{
		return "file-local-options/" + name+ "";
	}

	std::string MPVProperty::optionInfo(std::string name)
	{
		return "option-info/" + name+ "";
	}

	std::string MPVProperty::optionInfoName(std::string name)
	{
		return "option-info/" + name+ "/name";
	}
	std::string MPVProperty::optionInfoType(std::string name)
	{
		return "option-info/" + name+ "/type";
	}

	std::string MPVProperty::optionInfoSetFromCommandline(std::string name)
	{
		return "option-info/" + name+ "/set-from-commandline";
	}

	std::string MPVProperty::optionInfoSetLocally(std::string name)
	{
		return "option-info/" + name+ "/set-locally";
	}

	std::string MPVProperty::optionInfoDefaultValue(std::string name)
	{
		return "option-info/" + name+ "/default-value";
	}

	std::string MPVProperty::optionInfoMin(std::string name)
	{
		return "option-info/" + name+ "/min";
	}

	std::string MPVProperty::optionInfoMax(std::string name)
	{
		return "option-info/" + name+ "/max";
	}
	std::string MPVProperty::optionInfoChoices(std::string name)
	{
		return "option-info/" + name+ "/choices";
	}
